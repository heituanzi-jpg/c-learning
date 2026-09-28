#include <stdio.h>

int main () {
    int age = 20;
    int *p = &age;

    printf("顺门牌号看一眼: %d\n", *p);
    *p =21; 
    printf("age 现在: %d\n",age);
    return 0;
}