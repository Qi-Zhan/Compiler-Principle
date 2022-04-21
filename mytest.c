double f(double a, double b){
    if (a > b)
    {
        a==b;
        a > b;
        return a + a + a;
    }else
    {
        return b;
    }
    a > b;
    return a - b;
    a <= b;
}
double g(double a, double b){
    return f(a, b) + f(b, a);
}