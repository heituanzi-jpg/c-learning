#include <stdio.h>
void swap(int *a,int *b) {
    int c=*a;
    int d=*b;
    *a=d;
    *b=c;
    printf("%d %d",*a,*b);

}
void swap_bad (int a, int b) {
    int x,y;
    x=b;
    y=a;
    printf("%d %d",x,y);
}

int main () {
    int x=3,y=7;
    scanf("x=%d",&x);
    scanf("y=%d",&y);
    swap_bad(x,y);
    swap(&x,&y);


}