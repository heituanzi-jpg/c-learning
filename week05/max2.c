#include <stdio.h>
int max2(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}
int main () {
    printf("max2(3,7)=%d\n",max2(3,7));
    printf("max2(9,2)=%d\n",max2(9,2));
    printf("max2(9,9)=%d\n",max2(9,9));
    return 0;
}