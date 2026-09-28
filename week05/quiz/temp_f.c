#include <stdio.h>
double to_celsius(double f){
    double celsius;
    celsius=(f-32)*5/9;
    return celsius;
}
int main(){
    double f;
    printf("请输入华氏度：\n");
    scanf("%le",&f);
    printf("华氏度转摄氏度的值为:%.2f",to_celsius(f));
}