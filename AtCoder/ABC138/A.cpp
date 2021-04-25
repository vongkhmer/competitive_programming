/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    //do not forget to allocate extra 1 char for the null character
    char s[11];
    scanf("%s", s);
    if(a < 3200){
        printf("red\n");
    }else{
        printf("%s\n", s);
    }
    return 0;
}