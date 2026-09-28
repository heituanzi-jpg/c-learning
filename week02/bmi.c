#include <stdio.h>
int main(){
    double height , weight , bmi ;
    printf("请输入身高(米):");
    scanf("%lf",&height);
    printf("请输入体重(公斤):");
    scanf("%lf",&weight);
    bmi=weight/(height*height);
    printf("你的BMI是%.1f\n",bmi);
    return 0;
}