#include "gen.h"
using namespace llvm;
using namespace llvm::sys;
static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;
static std::map<std::string, GlobalVariable *> GlobalValues;
// static std::map<std::string, Value *> NamedValues;
static std::map<std::string, AllocaInst *> NamedValues;
// static std::map<AST *, Value *> mySymbolTable;
// static llvm::ValueSymbolTable *llvm_SymbolTable;
static llvm::BasicBlock *CurrentMerge = nullptr;
static llvm::BasicBlock *CurrentCond = nullptr;

static void InitializeModule()
{
    // Open a new context and module.
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("my cool ssc", *TheContext);

    // // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);
}
static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const std::string &VarName, Type* valuetype)
{
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(valuetype, 0, VarName.c_str());
    // return TmpB.CreateAlloca(Type::getDoubleTy(*TheContext), 0,VarName.c_str());
}
Value *codeGen::binaryop(AST *node){
    Value *L = codeGen::generate(node->child->at(0));
    Value *R = codeGen::generate(node->child->at(1));
    std::string type0 = node->child->at(0)->dtype;
    std::string type1 = node->child->at(1)->dtype;
    bool allint = (node->dtype == "int");
    // std::cout << type0 << type1 << std::endl;
    // convert type
    if (type0 != type1)
    {
        if (type1 == node->dtype)
        {
            L = Builder->CreateCast(Instruction::SIToFP, L, R->getType());
        }else{
            R = Builder->CreateCast(Instruction::SIToFP, R, L->getType());
        }
        
    }
    if (!L || !R)
        return nullptr;
    if (node->binaryop == "="){
        Value *Variable = NamedValues[std::string(node->child->at(0)->ID)];
        if (!Variable){ // 全局里面找
            Variable = GlobalValues[node->child->at(0)->ID];
        }
        Builder->CreateStore(R, Variable);
        return R;
    }
    if (node->binaryop == "+")
    {
        if (allint)
            return Builder->CreateAdd(L, R, "addtmp");
        else
        return Builder->CreateFAdd(L, R, "addtmp");
    }
    else if (node->binaryop == "-")
    {
        if (allint)
            return Builder->CreateSub(L, R, "subtmp");
        return Builder->CreateFSub(L, R, "subtmp");
    }
    else if (node->binaryop == "*") // a lot todo
    {
        if (allint)
            return Builder->CreateMul(L, R, "multmp");
        else
            return Builder->CreateFMul(L, R, "multmp");
    }
    else if (node->binaryop == "/") // a lot todo
    {
        if(allint)
            return Builder->CreateSDiv(L, R, "divtmp");
        return Builder->CreateFDiv(L, R, "divtmp");
    }
    else if (node->binaryop == "<")
    {
        if (allint)
        {
            return Builder->CreateICmpSLT(L, R, "complt");
        }

        return Builder->CreateFCmpULT(L, R, "complt");
    }
    else if (node->binaryop == ">")
    {
        if (allint)
        {
            return Builder->CreateICmpSGT(L, R, "compgt");
        }
        return Builder->CreateFCmpUGT(L, R, "compgt");
    }
    else if (node->binaryop == "==")
    {
        // return Builder->CreateFCmp
        if (allint)
            return Builder->CreateICmpEQ(L, R, "compeq");
        else
            return Builder->CreateFCmpOEQ(L, R, "compeq");
    }
    else if (node->binaryop == ">=")
    {
        if (allint)
        {
            return Builder->CreateICmpSGE(L, R, "compge");
        }
        return Builder->CreateFCmpUGE(L, R, "compge");
    }
    else if (node->binaryop == "<=")
    {
        if (allint)
        {
            return Builder->CreateICmpSLE(L, R, "comple");
        }
        return Builder->CreateFCmpULE(L, R, "comple");
    }
    else if (node->binaryop == "!=")
    {
        if (allint)
        {
            return Builder->CreateICmpNE(L, R, "compne");
        }
        return Builder->CreateFCmpUNE(L, R, "compne");
    }
    return nullptr;
}
GlobalVariable* codeGen::createGlobal(Type* type, std::string name){
    TheModule->getOrInsertGlobal(name, type);
    GlobalVariable* v = TheModule->getNamedGlobal(name);
    return v;
}
Type* str2type(std::string str){
    if (str == "int")
    {
        return Builder->getInt32Ty();
    }
    else if (str == "float")
    {
        return Builder->getFloatTy();
    }
    else if (str == "double")
    {
        return Builder->getDoubleTy();
    }
    else{
        printf("No Such Type in str2type\n");
        return Builder->getInt32Ty();
    }
}
codeGen::codeGen(){
    InitializeModule();
}
Value *codeGen::generate(AST *node){
    if (node->tokentype == "translation unit"){ // test first
        for (int i = 0; i < node->child->size(); i++)
        {
            if (node->child->at(i)->tokentype=="VarDecl") // global 
            {
                AST *ch = node->child->at(i);
                GlobalVariable *gv;
                if (ch->dtype == "int")
                {
                    gv = createGlobal(Builder->getInt32Ty(), ch->ID);
                    if (ch->child->size()==1)
                    {
                        Value *v = codeGen::generate(ch->child->at(0));
                        ConstantInt *CI = dyn_cast<ConstantInt>(v);
                        ConstantInt *const_int_val = ConstantInt::get(TheModule->getContext(), APInt(CI->getValue()));
                        gv->setInitializer(const_int_val);
                    }
                }
                else if (ch->dtype == "float")
                {
                    gv = createGlobal(Builder->getFloatTy(), ch->ID);
                    if (ch->child->size() == 1){
                        Value *v = codeGen::generate(ch->child->at(0));
                        ConstantFP *CI = dyn_cast<ConstantFP>(v);
                        ConstantFP *const_int_val = ConstantFP::get(TheModule->getContext(), APFloat(CI->getValueAPF()));
                        gv->setInitializer(const_int_val);
                    }
                }
                else if (ch->dtype == "double"){
                    // bug to do
                    gv = createGlobal(Builder->getDoubleTy(), ch->ID);
                    if (ch->child->size() == 1){
                        Value *v = codeGen::generate(ch->child->at(0));
                        ConstantFP *CI = dyn_cast<ConstantFP>(v);
                        ConstantFP *const_int_val = ConstantFP::get(TheModule->getContext(), APFloat(CI->getValueAPF()));
                        gv->setInitializer(const_int_val);
                    }
                }else{
                    printf("No such Type in Global\n");
                }
                GlobalValues.insert({ch->ID, gv});
            }
            else // function define
                codeGen::generate(node->child->at(i));
        }
        return nullptr;
    }
    else if (node->tokentype == "Constant")
    {
        if (node->dtype == "int")
        {
            APInt i = APInt(32, (int)node->dvalue, true);
            // printf("get int\n");
            return ConstantInt::get(*TheContext, APInt(i));
        }
        else if (node->dtype == "float")
        {
            // printf("get float\n");
            return ConstantFP::get(*TheContext, APFloat(node->dvalue));
        }else if(node->dtype == "double"){
            return ConstantFP::get(*TheContext, APFloat(node->dvalue));
        }
    }
    else if (node->tokentype == "Identifier")
    {
        AllocaInst *V_ = NamedValues[node->ID];
        if (!V_){
            // printf("Find variable name in Global\n");
            GlobalVariable *X = GlobalValues[node->ID];
            auto block = Builder->GetInsertBlock();
            return new LoadInst(str2type(node->dtype), X, node->ID, block);
        }
        return Builder->CreateLoad(V_->getAllocatedType(),V_, node->ID.c_str());
        // auto symbol = block->getValueSymbolTable();
        // Value* V = symbol->lookup(node->ID);
    }
    else if (node->tokentype == "BinaryOperator")
    {
        return binaryop(node);
    }
    else if (node->tokentype == "CallExpr") // 调用函数
    {
        Function *CalleeF = TheModule->getFunction(node->ID);
        if (!CalleeF)
            std::cout<<("Unknown function referenced")<<std::endl;
        std::vector<Value *> ArgsV;
        for (int i = 0 ; i < node->child->size(); ++i)
        {
            // ArgsV.push_back(Args[i]->codegen());
            ArgsV.push_back(codeGen::generate(node->child->at(i)));
            if (!ArgsV.back())
                return nullptr;
        }
        return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
    }
    else if (node->tokentype == "FunctionDecl") // 函数定义
    {
        int para = 0; // 判断有几个Parameter
        while (para < node->child->size()){
            if (node->child->at(para)->tokentype != "ParmVarDecl")
                break;
            else
                para++;
        }
        // std::vector<Type *> parameter(para, Type::getDoubleTy(*TheContext));
        std::vector<Type *> parameter;
        for (int i = 0; i < para; i++){
            // printf("%s\n", node->child->at(i)->dtype.c_str());
            if (node->child->at(i)->dtype == "int")
            {
                parameter.push_back(Type::getInt32Ty(*TheContext));
                // parameter[i] = (Type::getInt32Ty(*TheContext));
            }
            else if (node->child->at(i)->dtype == "float")
            {
                parameter.push_back(Type::getFloatTy(*TheContext));
                // parameter[i] = (Type::getFloatTy(*TheContext));
            }else //double
            {
                parameter.push_back(Type::getDoubleTy(*TheContext));
                // parameter[i] = (Type::getDoubleTy(*TheContext));
            }
        }
        FunctionType *FT;
        // std::vector<Type *> Doubles(para, Type::getDoubleTy(*TheContext));
        if (node->dtype == "int"){
            FT = FunctionType::get(Type::getInt32Ty(*TheContext), parameter, false);
        }
        else if (node->dtype == "float"){
            FT = FunctionType::get(Type::getFloatTy(*TheContext), parameter, false);
        }
        else // double
        {
            FT = FunctionType::get(Type::getDoubleTy(*TheContext), parameter, false);
        }
        Function *F =
            Function::Create(FT, Function::ExternalLinkage, node->ID, TheModule.get());
        unsigned Idx = 0;
        for (auto &Arg : F->args()) // 绑定参数
            Arg.setName(node->child->at(Idx++)->ID);
        Function *TheFunction = TheModule->getFunction(node->ID);
        TheFunction = F;
        BasicBlock *BB = BasicBlock::Create(*TheContext, "entry", TheFunction);
        Builder->SetInsertPoint(BB);
        NamedValues.clear();
        for (auto &Arg : TheFunction->args()){
            AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, std::string(Arg.getName()),Arg.getType());
            Builder->CreateStore(&Arg, Alloca);
            NamedValues[std::string(Arg.getName())] = Alloca;
        }
            // NamedValues[std::string(Arg.getName())] = &Arg;
        // printf("child is %d para is %d\n", node->child->size(),para);
        if (Value *RetVal = codeGen::generate(node->child->at(para))) // para 为 basic block 位置
        {
            // Finish off the function.
            Builder->CreateRet(RetVal);
            // Validate the generated code, checking for consistency.
            verifyFunction(*TheFunction);
            return TheFunction;
        }else
        {
            // Builder->CreateRet(nullptr);
            // Validate the generated code, checking for consistency.
            verifyFunction(*TheFunction);
            return TheFunction;
        }
        // Error reading body, remove function.
        TheFunction->eraseFromParent();
        // return nullptr;
    }
    else if (node->tokentype == "CompoundStmt")
    {
        if (node->child->size()==0)
        {
            // return nullptr;
        }
        for (int i = 0; i < node->child->size(); i++)
        {
            codeGen::generate(node->child->at(i));
        }

        // return codeGen::generate(node->child->at(node->child->size()-1)); // test
    }
    else if (node->tokentype == "ReturnStmt")
    {
        if (node->child->size()==0){
            // printf("1111\n11111\n");
            // return Builder->CreateRetVoid();
            
            return Builder->CreateRetVoid();
        }else{
            return Builder->CreateRet(codeGen::generate(node->child->at(0)));
        }
        
        // Builder.CreateRet(Builder.getInt32(0));
        return codeGen::generate(node->child->at(0));
    }
    else if (node->tokentype == "IfStmt")
    { 
        Value *CondV = codeGen::generate(node->child->at(0));
        // printf("get if\n");
        if (!CondV)
            return nullptr;
        // Convert condition to a bool by comparing non-equal to 0.
        // CondV = Builder->CreateFCmpONE(CondV, ConstantInt::get(*TheContext, APInt(i)), "ifcond");
        Function *TheFunction = Builder->GetInsertBlock()->getParent();
        // Create blocks for the then and else cases.  Insert the 'then' block at the
        // end of the function.
        BasicBlock *ThenBB = BasicBlock::Create(*TheContext, "then", TheFunction);
        BasicBlock *ElseBB = BasicBlock::Create(*TheContext, "else");
        BasicBlock *MergeBB = BasicBlock::Create(*TheContext, "merge");
        // printf("get if1\n");
        Builder->CreateCondBr(CondV, ThenBB, ElseBB);
        // printf("get if2\n");
        // Emit then value.
        Builder->SetInsertPoint(ThenBB);
        codeGen::generate(node->child->at(1));
        // if (!ThenV)
        //     return nullptr;
        // printf("elseelsel           selse\n");
        Builder->CreateBr(MergeBB);
        // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
        ThenBB = Builder->GetInsertBlock();
        // Emit else block.
        TheFunction->getBasicBlockList().push_back(ElseBB);
        Builder->SetInsertPoint(ElseBB);
        // printf("elseelselselse\n");
        // Value *ElseV = nullptr;
        if (node->child->size() == 3) // exist else
        {
            // printf("elseelselselse\n");
            codeGen::generate(node->child->at(2));
        }
        Builder->CreateBr(MergeBB);
        ElseBB = Builder->GetInsertBlock();
        TheFunction->getBasicBlockList().push_back(MergeBB);
        Builder->SetInsertPoint(MergeBB);
    }
    else if (node->tokentype == "ContinueStmt"){
        // BasicBlock b = Builder->GetInsertBlock()->getParent();
        Builder->CreateBr(CurrentCond);
    }
    else if (node->tokentype == "BreakStmt"){
        Builder->CreateBr(CurrentMerge);
    }
    else if (node->tokentype == "VarDecl"){ // 局部变量
        if (node->child->size()==1) // 有初始赋值
        {
            // printf("local\n");
            AllocaInst *temp = Builder->CreateAlloca(str2type(node->dtype), 0, "loadtmp");
            Value* va = codeGen::generate(node->child->at(0));
            Builder->CreateStore(va, temp, 0);
            NamedValues.insert({node->ID, temp});
        }else{
            AllocaInst * temp = Builder->CreateAlloca(str2type(node->dtype), 0, node->ID);
            NamedValues.insert({node->ID, temp});
        }
    }
    else if (node->tokentype == "ForStmt"){
        Function *TheFunction = Builder->GetInsertBlock()->getParent();
        BasicBlock *entryBB = BasicBlock::Create(*TheContext, "entry", TheFunction);
        BasicBlock *loopBB = BasicBlock::Create(*TheContext, "loop", TheFunction);
        BasicBlock *endLoopBB = BasicBlock::Create(*TheContext, "endloop", TheFunction);
        BasicBlock *endEntryBB = BasicBlock::Create(*TheContext, "endentry", TheFunction);
        Builder->CreateBr(entryBB);
        // entry
        Builder->SetInsertPoint(entryBB);
        if(node->child->size()==4){ // 有初始化
            codeGen::generate(node->child->at(0));
        }
        Value *EndCond = codeGen::generate(node->child->at(1)); // 判断条件
        Builder->CreateCondBr(EndCond, loopBB, endEntryBB);
        Builder->SetInsertPoint(loopBB);
        // loop
        codeGen::generate(node->child->at(3));
        Builder->CreateBr(endLoopBB);
        // endLoopBB
        Builder->SetInsertPoint(endLoopBB);
        codeGen::generate(node->child->at(2));
        Value *EndCond_ = codeGen::generate(node->child->at(1)); // 判断条件
        Builder->CreateCondBr(EndCond_, loopBB, endEntryBB);
        // endInit
        Builder->SetInsertPoint(endEntryBB);
        // Builder->CreateRet(initVal);
    }
    else if (node->tokentype == "WhileStmt"){

    }
    return nullptr;
}


codeGen::~codeGen()
{
}

void codeGen::print(){
    // printf("print successfully!\n");
    TheModule->print(errs(), nullptr);
}

int codeGen::generate_o(){
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target)
    {
        errs() << Error;
        return 1;
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    auto Filename = "output.o";
    std::error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    if (EC)
    {
        errs() << "Could not open file: " << EC.message();
        return 1;
    }

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType))
    {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*TheModule);
    dest.flush();

    outs() << "Generate " << Filename << " successfully!\n";
    return 0;
}