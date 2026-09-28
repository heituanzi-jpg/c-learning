#include <stdio.h>
void show_menu(){
    printf("===== 命令行计算器 =====\n");
    printf("1.加  2.减  3.乘  4.除\n");
    printf("5.历史记录  0.退出\n");
    printf("请选择：");
}


int main(){
    while (1) {
        int choice ;
        show_menu();
        scanf("%d",&choice);
        if (choice == 0){
            printf("再见！\n");
            break;
        }
        if(choice < 1 || choice >5){
            printf("没有这个选项\n");
            continue;
        }
        printf("【功能%d待实现】\n",choice);
    }
    return 0;
}