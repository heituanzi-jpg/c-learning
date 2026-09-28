#include <stdio.h>
double calc_max(double arr[],int n){
    double max =arr[0];
    for (int i=1;i<n;i++){
        if (arr[i]>max){
            max =arr[i];
        }
    }
    return max;
}

double calc_min(double arr[],int n){
    double min =arr[0];
    for (int i=1;i<n;i++){
        if (arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

double calc_avg(double arr[],int n){
    double sum = 0;
    for (int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    return sum / n;

}

int main(){
    double scores[5];
    printf("请输入5门成绩:\n");
    for (int i = 0 ; i< 5 ;i++){
        scanf("%lf",&scores[i]);
    }
    printf("最高分：%.1f\n",calc_max(scores,5));
    printf("最低分：%.1f\n",calc_min(scores,5));
    printf("平均分：%.1f\n",calc_avg(scores,5));
    return 0 ;
    

}