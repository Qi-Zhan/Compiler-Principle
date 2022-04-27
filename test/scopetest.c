int a = 0;
int f(int x)
{
    int c = 10;
    if (c==10)
    {
        int c = 3;
        a = a + c;
    }else{
        int c = 9;
        a = a + c;
    }

    return a+c;
}
int g(int x){
    return f(x);
}