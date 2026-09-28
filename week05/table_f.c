#include <stdio.h>
void print_table () {
    for (int i =1 ; i<=9 ;i++){
        for(int j =1;j<=i;j++){
            printf("%dx%d=%d\t",j,i,j*i);
        }printf("\n");
    }
}
int main (){
    print_table();
    printf("\n再来一遍\n\n");
    print_table();
    return 0;
}