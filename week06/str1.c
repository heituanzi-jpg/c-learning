#include <stdio.h>
int main(){
    char name[]="kay";
    printf("整串打印：%s\n",name);
    printf("占 %zu 格\n",sizeof(name));
    printf("逐个走：");
    for(int i =0; name[i] !='\0';i++){
        printf("%c.",name[i]);
    }
    printf("\n");
    return 0;
}