/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>

constexpr int mxN = 1e5;
int a[mxN];
int b[mxN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &b[i]);
    }
    int product = 0;
    for(int i = 0 ; i < n ; i++){
        //product definition
        product += a[i] * b[i];
    }
    if(product == 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}