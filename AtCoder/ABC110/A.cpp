/*
 * author: vongkh
 * created: Sat Dec 26 2020
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

//store the 3 digits 
int digit[3];

void solve(){
    scanf("%d %d %d",&digit[0], &digit[1], &digit[2]);
    //if the ans is (ab) + c == 10 *a + b + c,
    //then it is optimal to pick the biggest digit as a
    sort(digit, digit + 3);
    int ans = 10 * digit[2] + digit[1] + digit[0];
    printf("%d\n", ans);
}

int main(){
    solve();
}
