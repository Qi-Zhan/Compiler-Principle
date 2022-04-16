int f(int a, int b){
    return 1;
}
int main(){
    int a = 0;
    int i=2;
    for (i = 0; i < 10; i=i+1)
    {
        a = a + i;
    }
    if (a>10)
    {
        int b = 2;
    }else
    {
        int b = 3;
    }
    int c = f(1,a);
    return a;
}