#include <stdio.h>
int main(){
    printf("int占%zu字节\n",sizeof(int));
    printf("double占%zu字节\n",sizeof(double));
    printf("char占%zu字节\n",sizeof(char));
    return 0;
} 