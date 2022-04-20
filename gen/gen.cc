#include "gen.h"
using namespace llvm;
using namespace llvm::sys;
static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;
static std::map<std::string, Value *> NamedValues;
static void InitializeModule()
{
    // Open a new context and module.
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("my cool ssc", *TheContext);

    // // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);
}

codeGen::codeGen(){
    InitializeModule();
}
Value *codeGen::generate(AST *node){
    if (node->tokentype == "translation unit"){ // test first
        for (int i = 0; i < node->child->size(); i++)
        {
            codeGen::generate(node->child->at(i));
        }
        return nullptr;
    }
    else if (node->tokentype == "Constant")
    {
        if (node->dtype == "int")
        {
            APInt i = APInt(32, (int)node->dvalue);
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
        Value *V = NamedValues[node->ID];
        return V;
    }
    else if (node->tokentype == "BinaryOperator")
    {
        Value *L = codeGen::generate(node->child->at(0));
        Value *R = codeGen::generate(node->child->at(1));
        if (!L || !R)
            return nullptr;
        if (node->binaryop=="+")
        {
            return Builder->CreateFAdd(L, R, "addtmp");
        }else if (node->binaryop == "-") 
        {
            return Builder->CreateFSub(L, R, "subtmp");
        }
        else if (node->binaryop == "*") // a lot todo
        {
            return Builder->CreateFMul(L, R, "subtmp");
        }
        else if (node->binaryop == "/") // a lot todo
        {
            return Builder->CreateFDiv(L, R, "subtmp");
        }else if (node->binaryop == "<")
        {
            return Builder->CreateFCmpULT(L, R, "complt");
        }
        else if (node->binaryop == ">")
        {
            return Builder->CreateFCmpUGT(L, R, "compgt");
        }
        else if (node->binaryop == "==")
        {
            return Builder->CreateFCmpOEQ(L, R, "compeq");
        }
        else if (node->binaryop == ">=")
        {
            return Builder->CreateFCmpUGE(L, R, "compge");
        }
        else if (node->binaryop == "<=")
        {
            return Builder->CreateFCmpULE(L, R, "comple");
        }
        else if (node->binaryop == "!=")
        {
            return Builder->CreateFCmpUNE(L, R, "compne");
        }
    }
    else if (node->tokentype == "CallExpr") // 调用函数
    {
        Function *CalleeF = TheModule->getFunction(node->ID);
        // if (!CalleeF)
        //     return LogErrorV("Unknown function referenced");
        // if (CalleeF->arg_size() != Args.size())
        //     return LogErrorV("Incorrect # arguments passed");

        std::vector<Value *> ArgsV;
        for (int i = 0 ; i <= node->child->size(); ++i)
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
        if (node->dtype == "double")
        {
        }
        std::vector<Type *> Doubles(para,Type::getDoubleTy(*TheContext));
        FunctionType *FT =
            FunctionType::get(Type::getDoubleTy(*TheContext), Doubles, false);
            // Type::getInt32Ty
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
        for (auto &Arg : TheFunction->args())
            NamedValues[std::string(Arg.getName())] = &Arg;
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
            Builder->CreateRet(nullptr);
            // Validate the generated code, checking for consistency.
            verifyFunction(*TheFunction);
            return TheFunction;
        }
        
        // Error reading body, remove function.
        TheFunction->eraseFromParent();
        return nullptr;
    }
    else if (node->tokentype == "CompoundStmt")
    {
        if (node->child->size()==0)
        {
            return nullptr;
        }

        return codeGen::generate(node->child->at(0)); // test
    }
    else if (node->tokentype == "ReturnStmt")
    {
        return codeGen::generate(node->child->at(0));
    }
    else if (node->tokentype == "IfStmt")
    {
        Value* CondV =  codeGen::generate(node->child->at(0));
        if (!CondV)
            return nullptr;
        // Convert condition to a bool by comparing non-equal to 0.
        // APInt i = APInt(1, 0);
        // CondV = Builder->CreateFCmpONE(CondV, ConstantInt::get(*TheContext, APInt(i)), "ifcond");
        Function *TheFunction = Builder->GetInsertBlock()->getParent();
        // Create blocks for the then and else cases.  Insert the 'then' block at the
        // end of the function.
        BasicBlock *ThenBB = BasicBlock::Create(*TheContext, "then", TheFunction);
        BasicBlock *ElseBB = BasicBlock::Create(*TheContext, "else");
        BasicBlock *MergeBB = BasicBlock::Create(*TheContext, "ifcont");
        Builder->CreateCondBr(CondV, ThenBB, ElseBB);
        // Emit then value.
        Builder->SetInsertPoint(ThenBB);
        Value *ThenV = codeGen::generate(node->child->at(1));
        if (!ThenV)
            return nullptr;
        Builder->CreateBr(MergeBB);
        // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
        ThenBB = Builder->GetInsertBlock();

        // Emit else block.
        TheFunction->getBasicBlockList().push_back(ElseBB);
        Builder->SetInsertPoint(ElseBB);

        Value *ElseV = nullptr;
        if (node->child->size() == 3) // no else
        {
            // printf("elseelselselse\n");
            ElseV = codeGen::generate(node->child->at(2));
        }
        if (!ElseV)
            return nullptr;

        Builder->CreateBr(MergeBB);
        // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
        ElseBB = Builder->GetInsertBlock();

        // Emit merge block.
        TheFunction->getBasicBlockList().push_back(MergeBB);
        Builder->SetInsertPoint(MergeBB);
        PHINode *PN = Builder->CreatePHI(Type::getDoubleTy(*TheContext), 2, "iftmp");

        PN->addIncoming(ThenV, ThenBB);
        PN->addIncoming(ElseV, ElseBB);
        return PN;
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