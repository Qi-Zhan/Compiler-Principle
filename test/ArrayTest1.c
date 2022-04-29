
int b = 0;
int f(int c)
{
    int a[3]= {112,2,3};
    int d = 0;
    int num = 0;
    for (d = 0; d < 3; d = d + 1)
    {
        num = num + a[d];
    }

    return num;
}