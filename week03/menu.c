#include <stdio.h>
int main (){
    int choice;
    int number;
    printf("这是一个菜单：输入1判断正负数，输入2退出\n");
    scanf("%d",&choice);

    switch (choice){
        case 1:
        printf("请输入一个数\n");
        scanf("%d",&number);
        if(number>0){
            printf("%d是个正数\n",number);
        }else if(number==0){
            printf("%d是零\n",number);
        }else{
            printf("%d这是一个负数\n",number);
        }break;
        case 2:
        printf("退出\n");
        break;
        default:
        printf("没有这个选项\n");
        break;

    }
}