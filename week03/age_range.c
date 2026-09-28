#include <stdio.h>
int main () {
    int age;
    printf("请输入年龄：");
    scanf("%d",&age);
    if (age >= 0 && age <= 150){
        printf("合法年龄\n");
    }else{
        printf("你在逗我\n");
    }
    return 0;
}
