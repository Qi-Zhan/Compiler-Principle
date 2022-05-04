#include <stdio.h>
// double f(double,double);
// double g(double, double);
// int f(int);
// int f(int a[],int n);
// float f(int);
// extern int b[4];
// int a[4] = {4, 1, 6, 8};
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6,1,25,8,111,4,-1};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
// int main()
// {
//     printf("%d\n", f(a,4));
//     for (int i = 0; i < 4; i++)
//     {
//         printf("%d %d\n",a[i], b[i]);
//     }
//     // printf("%f\n", g(1110.0, 400.0));
//     // printf("%d\n", g(100));
//     // printf("%f\n", f(10));
    
//     return 0;
// }