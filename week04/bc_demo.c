#include <stdio.h>
int main() {
    printf("continue组:");
    for (int i = 1;i<=10;i++){
        if (i==5){
            continue;
        }printf("%d",i);
    }printf("\nbreak 组：");
    for (int i=1;i<=10;i++){
        if (i==7){
            break;
        }printf("%d",i);
    }printf("\n");
    return 0;
}