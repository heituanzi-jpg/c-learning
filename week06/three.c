#include <stdio.h>
int main(){
    int score[3]={33,66,99};
    int sum=0;
    for(int i = 0;i<3;i++){
        printf("第%d门:%d",i,score[i]);
        sum=sum+score[i];
    }
    printf("总分为:%d",sum);
    return 0;



}