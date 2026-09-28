#include <stdio.h>
double power (double base,int n) {
    double answer = 1;
    if (n >= 0){
        if (n!=1){
            while(n!=0){
                answer=base*answer;
                n=n-1; 
            }
            return answer;
        }else{
            answer=base;
            return answer;
        }    
    }else if(n==0){
        answer=1;
        return answer;
    }else{
        printf("这个现在还没有功能");
        return -1;
    }

}


int main () {
    printf("power(2,10)->:%g",power(2,10));
    printf("power(5,0)->:%g",power(5,0));
    printf("power(1.5,3)->%g:",power(1.5,3));
    return 0;
}