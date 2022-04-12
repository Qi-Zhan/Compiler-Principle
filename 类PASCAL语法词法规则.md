## 词法

**保留字**

```pascal
program	procedure function
begin end if then else case while do until repeat for to goto downto
const var array type record of packed
and or not div mod
integer real boolean char
false true
```


## 语法

```pascal
program program_name; {程序首部}
{常量说明}
{类型说明}
{变量说明}
{函数或过程说明}
{执行部分}
.
```
```pascal
Function function_name(para):
    {常量说明}
    {类型说明}
    {变量说明}
    {执行部分} function_name := expr
;
```
```pascal
I if <expr> then statement ;
II if <expr> then statement else statement;
```

## 语义
```
decl → var-list : type var-list.dtype = type.dtype
var-list1 → var-list2, id id .dtype = var-list1.dtype 
var-list2.dtype = var-list1.dtype
var-list → id id .dtype = var-list.dtype
type → integer type.dtype = integer
type → real type.dtype = real
```

