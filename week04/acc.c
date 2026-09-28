#include <stdio.h>
int main (){
    int N,sum=0;
    printf("请输入一个整数N:");
    scanf("%d",&N);
    for(int i = 1;i<=N;i++){
        sum=sum+i;
    }
    printf("1+2+3+...+N的值是%d",sum);

}