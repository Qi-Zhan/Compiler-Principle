## 词法

**保留字**




## 语法
```c
//变量声明/定义
int a,b,c = 45;
int f;
float d = 1.4;
int a = 6 + 7;
```

```c
TranslationUnitDecl 0x6f8708 <<invalid sloc>> <invalid sloc>
|-VarDecl 0x739480 <mytest.c:1:1, col:5> col:5 a 'int'
|-VarDecl 0x739548 <col:1, col:7> col:7 b 'int'
|-VarDecl 0x7395c8 <col:1, col:13> col:9 c 'int' cinit
| `-IntegerLiteral 0x739630 <col:13> 'int' 45
|-VarDecl 0x739688 <line:2:1, col:5> col:5 f 'int'
|-VarDecl 0x739708 <line:3:1, col:11> col:7 d 'float' cinit
| `-ImplicitCastExpr 0x739790 <col:11> 'float' <FloatingCast>
|   `-FloatingLiteral 0x739770 <col:11> 'double' 1.400000e+00
`-VarDecl 0x7397c0 prev 0x739480 <line:4:1, col:13> col:5 a 'int' cinit
  `-BinaryOperator 0x739868 <col:9, col:13> 'int' '+'
    |-IntegerLiteral 0x739828 <col:9> 'int' 6
    `-IntegerLiteral 0x739848 <col:13> 'int' 7
```

```c
函数定义
int f(int b, float c){
    return b + c;
}
```
```c
`-FunctionDecl 0x6605e0 <mytest.c:1:1, line:3:1> line:1:5 f 'int (int, float)'
  |-ParmVarDecl 0x660480 <col:7, col:11> col:11 used b 'int'
  |-ParmVarDecl 0x660500 <col:14, col:20> col:20 used c 'float'
  `-CompoundStmt 0x6607a8 <col:22, line:3:1>
    `-ReturnStmt 0x660798 <line:2:5, col:16>
      `-ImplicitCastExpr 0x660780 <col:12, col:16> 'int' <FloatingToIntegral>
        `-BinaryOperator 0x660760 <col:12, col:16> 'float' '+'
          |-ImplicitCastExpr 0x660748 <col:12> 'float' <IntegralToFloating>
          | `-ImplicitCastExpr 0x660718 <col:12> 'int' <LValueToRValue>
          |   `-DeclRefExpr 0x6606d8 <col:12> 'int' lvalue ParmVar 0x660480 'b' 'int'
          `-ImplicitCastExpr 0x660730 <col:16> 'float' <LValueToRValue>
            `-DeclRefExpr 0x6606f8 <col:16> 'float' lvalue ParmVar 0x660500 'c' 'float'
```
## 语义
```

```

