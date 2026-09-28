#include <stdio.h>
int main() {
    double f,c;
    printf("请输入华氏温度：\n");
    scanf("%lf",&f);
    c=(f-32)*5/9;
    printf("摄氏温度是%.2f度\n",c);
    return 0;

}