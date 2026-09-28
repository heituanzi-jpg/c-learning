#include <stdio.h>
int main(){
    int reverse[5];
    for(int i = 4;i >= 0;i--){
        scanf("%d",&reverse[i]);
    }
    for(int i = 0;i<=4;i++){
        printf("%d ",reverse[i]);
    }
    return 0;
}