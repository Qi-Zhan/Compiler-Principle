int a = 1;
int f(int x)
{
    int c = 0;
    if (x>0)
    {
        return c;
    }else{
        a = a + c;
    }
    return a;
}
int g(int x){
    return f(x);
}