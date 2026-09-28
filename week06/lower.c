#include <stdio.h>
int main () {
    char s[]="HeLLo";
    for(int i = 0 ; s[i] != '\0' ; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i]+32;
        }else{
            continue;
        }

    }
    printf("转换结果：%s",s);
}