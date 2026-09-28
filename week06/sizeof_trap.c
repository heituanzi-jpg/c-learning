#include <stdio.h>
void try_measure(int arr[]){
    printf("函数里sizeof(arr)=%zu\n ",sizeof(arr));
}
int main(){
    int a[10];
    printf("main里sizeof(a)=%zu\n",sizeof(a));
    printf("main里个数=%zu\n",sizeof(a)/sizeof(a[0]));
    try_measure(a);
    return 0;
}