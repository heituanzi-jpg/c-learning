#include <stdio.h>
int is_leap(int year) {
    if ((year % 4 == 0 && year %100 != 0) || (year % 400 == 0)){
        return 1;
    }else{
        return 0;
    }
}
int main () {
    printf("2024->%d\n",is_leap(2024));
    printf("1900->%d\n",is_leap(1900));
    printf("2000->%d\n",is_leap(2000));
    printf("2026->%d\n",is_leap(2026));
    return 0;
}