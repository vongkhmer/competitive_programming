/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <stdio.h>

int n;
const int mxN = 100;
int a[mxN];

int main(){
    scanf("%d", &n);
    //first we calculate the denominator 1/a[0] + ... + 1/a[n-1]
    double denominator = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        denominator += 1.0 / a[i];
    }
    //then we inverse the denominator
    double ans = 1.0 / denominator;
    printf("%.9lf\n", ans);
    return 0;
}