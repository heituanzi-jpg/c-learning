#include <stdio.h>
int main(){
    int age,year;
    printf("你几岁？");
    scanf("%d",&age);
    year=2026-age;
    printf("你出生于%d年\n",year);
    return 0;


}