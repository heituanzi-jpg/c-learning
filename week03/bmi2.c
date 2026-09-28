#include <stdio.h>
int main(){
    double height , weight , bmi ;
    printf("请输入身高(米):");
    scanf("%lf",&height);
    printf("请输入体重(公斤):");
    scanf("%lf",&weight);
    bmi=weight/(height*height);
    if(bmi<18.5){
        printf("你的BMI是%.1f,评价：偏瘦\n",bmi);
    }else if(bmi >= 18.5 && bmi < 24){
        printf("你的BMI是%.1f,评价：标准\n",bmi);
    }else if(bmi >= 24 && bmi < 28){
        printf("你的BMI是%.1f,评价：超重\n",bmi);
    }else{printf("你的BMI是%.1f,评价：肥胖\n",bmi);
    }return 0;

    
    
}