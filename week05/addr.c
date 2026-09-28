#include <stdio.h>
int main() {
    int age =20;
    printf("age里的值:%d\n",age);
    printf("age的门牌号:%p\n",(void*)&age);
    return 0;
}