#include <stdio.h>
int main(){
    int num;
    printf("请输入一个整数:");
    scanf("%d",&num);

    if (num>0){
        printf("%d 是正数\n",num);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    }else if(num<0){
        printf("%d是负数\n",num);
    }else{
        printf("这是零\n");
    }
    return 0;
}