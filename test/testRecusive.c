int f(int n){
    int res = 0;
    if (n <= 1)
    {
        res = n;
    }else{
        res = f(n - 1) + f(n - 2);
    }
    return res;
}