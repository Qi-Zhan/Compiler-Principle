## 词法

**保留字**

```pascal
program	procedure function
begin end if then else case while do until repeat for to goto downto
const var array type record of packed
and or not div mod
```





## 语法

```pascal
program program_name;

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

