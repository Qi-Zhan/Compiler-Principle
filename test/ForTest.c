int a = 1;
int f(int x)
{
    int c = 0;
    int i = 0;
    int j = 0;
    for ( i = 0; i < x; i=i+1)
    {
        for ( j = 0; j < x; j=j+1)
        {
            c = c + i + j;
        }
    }
    return c;
}
int g(int x){
    return f(x);
}