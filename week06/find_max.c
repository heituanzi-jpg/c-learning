#include <stdio.h>
int find_max(int arr[],int n){
    int max = arr[0];
    for (int i =1 ; i < n ;i++ ){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int a[]={3,7,2,9,5};
    int b[]={-5,-1,-8};
    int c[]={4};
    printf("%d\n",find_max(a,5));
    printf("%d\n",find_max(b,3));
    printf("%d\n",find_max(c,1));
    return 0;

}