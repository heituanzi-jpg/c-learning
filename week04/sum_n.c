#include <stdio.h>
int main() {
    int n,sum=0;
    printf("请输入N:");
    scanf("%d",&n);
    for (int i =1;i<=n;i++){
        sum=sum+i;
    }printf("1加到%d=%d\n",n,sum);
    return 0;
}
