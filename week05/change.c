#include <stdio.h>
void change (int x){
    x=99;
    printf("函数里x = %d\n",x);
}
int main() {
    int a=10;
    change(a);
    printf("main里a=%d\n",a);
    return 0;
}