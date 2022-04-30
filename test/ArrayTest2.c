int b[4] = {1, 2, 3, 4};
int f(int a[], int n)
{

    int num = 0;
    int i = b[3];
    
    for (i = 0; i < n; i=i+1)
    {
        num = num + a[i] + b[i];
        a[i] = a[i] * 2;
    }

    return num;
}