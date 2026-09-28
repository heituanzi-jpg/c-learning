#include <stdio.h>
int main(){
    int sum=0;
    for (int i=1;i<=100;i++){
        sum =sum+i;
    }printf("1+2+...+100=%d\n",sum);
    printf("高斯公式对照：%d\n",100*101/2);
    return 0;
}