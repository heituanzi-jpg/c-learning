#include <stdio.h>
int main(){
    int grade;
    printf("请输入你的成绩：");
    scanf("%d",&grade);
    if(grade<60&&grade>=0){
        printf("不及格\n");
    }else if(grade>=60 && grade<=74){
        printf("及格\n");
    }else if(grade>=75 && grade<=89){
        printf("良好\n");
    }else if(grade>=90&&grade<=100){
        printf("优秀");
    }else{
        printf("输入有误");

    }return 0;


}