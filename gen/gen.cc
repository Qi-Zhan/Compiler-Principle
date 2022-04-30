#include "gen.h"
using namespace llvm;
using namespace llvm::sys;
static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;
static std::map<std::string, GlobalVariable *> GlobalValues;
static std::map<std::string, AllocaInst *> NamedValues;
static std::map<AST *, AllocaInst *> mySymbolTable;
static llvm::BasicBlock *CurrentMerge = nullptr;
static llvm::BasicBlock *CurrentCond = nullptr;

static void InitializeModule()
{
    // Open a new context and module.
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("my cool ssc", *TheContext);
    // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);
}
Type *str2type(std::string str)
{

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
    else if (str=="int*"){
        // return Builder->getInt32Ty();
        return Builder->getInt32Ty()->getPointerTo();
    }
    else if (str == "float*")
    {
        return Builder->getFloatTy()->getPointerTo();
    }
    else if (str == "double*")
    {
        return Builder->getDoubleTy()->getPointerTo();
    }
    else if(str=="void"){
        return Builder->getVoidTy();
    }
    printf("No Such Type in str2type\n");
    return Builder->getInt32Ty();
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
        Value *Variable;
        if (node->child->at(0)->tokentype == "ArraySubscriptExpr")
        {
            AST *ch = node->child->at(0);
            Value *V = codeGen::generate(ch->child->at(1)); // 下标
            if (ch->child->at(0)->ref->tokentype == "ParmVarDecl"){ // 数组作为参数
                auto point_to_array = mySymbolTable[ch->child->at(0)->ref];
                auto array = Builder->CreateLoad(point_to_array);
                Variable = Builder->CreateGEP(array, V, "array_index");
            }else{ 
                AllocaInst *array_alloc = mySymbolTable[ch->child->at(0)->ref]; //局部数组
                if (!array_alloc) // 全局数组
                {
                    GlobalVariable *array_alloc = GlobalValues[ch->child->at(0)->ID];
                    Variable = Builder->CreateGEP(str2type(ch->dtype), array_alloc, V, "global_array_index");
                }
                else
                {
                    Variable = Builder->CreateGEP(array_alloc, V, "array_index");
                }
            }

        }else{
            Variable = mySymbolTable[node->child->at(0)->ref];
        }
        if (!Variable)
        { // 全局里面找
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
    else if(node->binaryop == "&&"){
        return Builder->CreateAnd(L, R, "land");
    }
    else if(node->binaryop == "||"){
        return Builder->CreateOr(L, R, "lor");
    }
    return nullptr;
}
GlobalVariable* codeGen::createGlobal(Type* type, std::string name){
    TheModule->getOrInsertGlobal(name, type);
    GlobalVariable* v = TheModule->getNamedGlobal(name);
    return v;
}

codeGen::codeGen(){
    InitializeModule();
}
int codeGen::createGlobalt(AST*ch){
    GlobalVariable *gv;
    if (ch->dtype == "int")
    {
        gv = createGlobal(Builder->getInt32Ty(), ch->ID);
        if (ch->child->size() == 1)
        {
            Value *v = codeGen::generate(ch->child->at(0));
            ConstantInt *CI = dyn_cast<ConstantInt>(v);
            ConstantInt *const_int_val = ConstantInt::get(TheModule->getContext(), APInt(CI->getValue()));
            gv->setInitializer(const_int_val);
        }
        else
        {
            ConstantInt *const_int_val = ConstantInt::get(TheModule->getContext(), APInt(32, 0));
            gv->setInitializer(const_int_val);
        }
    }
    else if (ch->dtype == "float")
    {
        gv = createGlobal(Builder->getFloatTy(), ch->ID);
        if (ch->child->size() == 1)
        {
            Value *v = codeGen::generate(ch->child->at(0));
            if (v->getType() != Builder->getFloatTy())
                v = Builder->CreateCast(Instruction::SIToFP, v, Builder->getFloatTy());
            ConstantFP *CI = dyn_cast<ConstantFP>(v);
            ConstantFP *const_int_val = ConstantFP::get(TheModule->getContext(), APFloat(CI->getValueAPF()));
            gv->setInitializer(const_int_val);
        }
        else
        {
            float a = 0;
            ConstantFP *const_float_val = ConstantFP::get(TheModule->getContext(), APFloat(a));
            gv->setInitializer(const_float_val);
        }
    }
    else if (ch->dtype == "double")
    {
        // bug to do
        gv = createGlobal(Builder->getDoubleTy(), ch->ID);
        if (ch->child->size() == 1)
        {
            Value *v = codeGen::generate(ch->child->at(0));
            ConstantFP *CI = dyn_cast<ConstantFP>(v);
            ConstantFP *const_int_val = ConstantFP::get(TheModule->getContext(), APFloat(CI->getValueAPF()));
            gv->setInitializer(const_int_val);
        }
        else
        {
            double a = 0;
            ConstantFP *const_float_val = ConstantFP::get(TheModule->getContext(), APFloat(a));
            gv->setInitializer(const_float_val);
        }
    }
    else
    {
        printf("No such Type in Global\n");
    }
    GlobalValues.insert({ch->ID, gv});
    return 0;
}
int codeGen::createGlobalarray(AST* node){
    Type *type = str2type(node->dtype.substr(0, node->dtype.size() - 1));
    ArrayType *ArrayTy_0 = ArrayType::get(type, node->length);
    PointerType *PointerTy_1 = PointerType::get(ArrayTy_0, 0);
    GlobalVariable *gv = codeGen::createGlobal(ArrayTy_0, node->ID);
    // GlobalVariable *gv = new GlobalVariable(*TheModule, ArrayTy_0, false, GlobalValue::CommonLinkage, 0, node->ID);
    if (node->child->size()==0) // 初始为0
    {
        ConstantAggregateZero *const_array_2 = ConstantAggregateZero::get(ArrayTy_0);
        // Global Variable Definitions
        gv->setInitializer(const_array_2);
    }else{
        std::vector<llvm::Constant *> values;
        std::string childtype = node->child->at(0)->dtype;
        for (int i = 0; i < node->child->size(); i++)
        {
            Value *v = codeGen::generate(node->child->at(i));
            if (childtype=="int")
            {
                ConstantInt *CI = dyn_cast<ConstantInt>(v);
                values.push_back(CI);
            }else{
                ConstantFP *CI = dyn_cast<ConstantFP>(v);
                values.push_back(CI);
            }
        }
        llvm::Constant *init = llvm::ConstantArray::get(ArrayTy_0, values);
        gv->setInitializer(init);
    }
    GlobalValues.insert({node->ID, gv});

    return 0;
}
int codeGen::createArray(AST* node){
    ArrayType* arrayType = ArrayType::get(str2type(node->dtype.substr(0, node->dtype.size() - 1)), node->length);
    APInt i = APInt(32, (int)node->length, true);
    AllocaInst * array_alloc = Builder->CreateAlloca(arrayType, ConstantInt::get(*TheContext, APInt(i)), node->ID);
    mySymbolTable.insert({node, array_alloc}); // 加入符号表
    for (int i = 0; i < node->child->size(); i++) // 初始化
    {
        Value *V = codeGen::generate(node->child->at(i));
        // auto zero = ConstantInt::get(*TheContext, llvm::APInt(32, 0, true));
        auto index = ConstantInt::get(*TheContext, llvm::APInt(32, i, true));
        Value* ptr =  Builder->CreateGEP(array_alloc, index, "array_index");
        Builder->CreateStore(V, ptr);
        // auto ptr = GetElementPtrInst::Create(array_alloc, {zero, index}, " ", bb);
    }
    return 0;
}
Value *codeGen::generate(AST *node){
    if (node->tokentype == "translation unit"){ // 全局变量与函数
        for (int i = 0; i < node->child->size(); i++)
        {
            if (node->child->at(i)->tokentype=="VarDecl") // global 
            {
                AST *ch = node->child->at(i);
                if(ch->length == 0) // 声明全局变量
                    codeGen::createGlobalt(ch);
                else // 全局数组
                    codeGen::createGlobalarray(ch);
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
        // printf("Find variable name %s \n", node->ID.c_str());
        AllocaInst *V = mySymbolTable[node->ref];
        if (!V) 
        {
            // printf("Find variable name in Global\n");
            GlobalVariable *X = GlobalValues[node->ID];
            auto block = Builder->GetInsertBlock();
            return new LoadInst(str2type(node->dtype), X, node->ID, block);
        }
        // printf("Find variable name %s \n", node->ID.c_str());
        return Builder->CreateLoad(V->getAllocatedType(),V, node->ID.c_str());
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
        std::vector<Type *> parameter;
        for (int i = 0; i < para; i++){
            // printf("%s\n", node->child->at(i)->dtype.c_str());
            parameter.push_back(str2type(node->child->at(i)->dtype));
        }
        FunctionType *FT;
        FT = FunctionType::get(str2type(node->dtype), parameter, false);
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
        Idx = 0;
        for (auto &Arg : TheFunction->args()){
            AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, std::string(Arg.getName()),Arg.getType());
            Builder->CreateStore(&Arg, Alloca);
            mySymbolTable.insert({node->child->at(Idx++), Alloca}); // 函数参数map
            NamedValues[std::string(Arg.getName())] = Alloca;
        }
        // printf("child is %d para is %d\n", node->child->size(),para);
        if (Value *RetVal = codeGen::generate(node->child->at(para))) // para 为 compoundStmt 位置
        {
            // Finish off the function.
            Builder->CreateRet(RetVal);
            // Validate the generated code, checking for consistency.
            verifyFunction(*TheFunction);
            return TheFunction;
        }else
        {
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
        if (node->length>0) // 数组
        {
            codeGen::createArray(node);
            return nullptr;
        }
        //变量
        if (node->child->size()==1) // 有初始赋值
        {
            // printf("local\n");
            AllocaInst *temp = Builder->CreateAlloca(str2type(node->dtype), 0, "loadtmp");
            Value* va = codeGen::generate(node->child->at(0));
            Builder->CreateStore(va, temp, 0);
            NamedValues.insert({node->ID, temp});
            mySymbolTable.insert({node, temp}); // 局部变量map
        }
        else
        {
            AllocaInst * temp = Builder->CreateAlloca(str2type(node->dtype), 0, node->ID);
            NamedValues.insert({node->ID, temp});
            mySymbolTable.insert({node, temp});
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
        Function *TheFunction = Builder->GetInsertBlock()->getParent();
        BasicBlock *entryBB = BasicBlock::Create(*TheContext, "entry", TheFunction);
        BasicBlock *loopBB = BasicBlock::Create(*TheContext, "loop", TheFunction);
        BasicBlock *endEntryBB = BasicBlock::Create(*TheContext, "endentry", TheFunction);
        Builder->CreateBr(entryBB);
        Builder->SetInsertPoint(entryBB);
        Value *EndCond = codeGen::generate(node->child->at(0)); // 判断条件
        Builder->CreateCondBr(EndCond, loopBB, endEntryBB);
        Builder->SetInsertPoint(loopBB);
        // loop
        codeGen::generate(node->child->at(1));
        Value *EndCond_ = codeGen::generate(node->child->at(0)); // 判断条件
        Builder->CreateCondBr(EndCond_, loopBB, endEntryBB);
        // endInit
        Builder->SetInsertPoint(endEntryBB);
    }
    else if (node->tokentype == "ArraySubscriptExpr"){ // 数组访问
        Value *V = codeGen::generate(node->child->at(1)); // 下标
        AllocaInst *array_alloc = mySymbolTable[node->child->at(0)->ref];
        if(!array_alloc){ // 全局数组
            auto array_alloc = GlobalValues[node->child->at(0)->ID];
            if(!array_alloc){
                printf("global array wrong!!!\n");
            }
            auto ptr = Builder->CreateGEP(array_alloc, std::vector<Value *>{ConstantInt::get(Type::getInt32Ty(*TheContext), 0), V});
            // Value *ptr = Builder->CreateGEP(array_alloc, V, "global_array_index");
            return Builder->CreateLoad(ptr, "load_global_array");

        }
        if (node->child->at(0)->ref->tokentype == "ParmVarDecl") // 数组作为参数
        {
            auto point_to_array = mySymbolTable[node->child->at(0)->ref];
            auto array = Builder->CreateLoad(point_to_array);
            Value *ptr = Builder->CreateGEP(array, V, "array_index");
            return Builder->CreateLoad(ptr, "load_array");
        }
        Value *ptr = Builder->CreateGEP(array_alloc, V, "array_index");
        return Builder->CreateLoad(ptr, "load_array");
    }
    return nullptr;
}


codeGen::~codeGen()
{
}

void codeGen::print(){
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