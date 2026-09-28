#include <stdio.h>
int main () {
//主要是循环 注意内层条件循环完再循环内层 注意的就是上面的grid.c是方方正正的 而这个是呈现直角三角形
//通过对grid.c的观察 注意到 i与j需要翻过来 本质上还是蒙题目
    for (int i=1; i<=9 ; i++){
        for(int j=1;j<=i;j++){
            printf("%dx%d=%d\t",j,i,j*i);
        }
        printf("\n");
    }
    return 0;
}
//第二次看发现了 内圈是不会累加的 我之前并不理解这一点 反而浪费了很多时间