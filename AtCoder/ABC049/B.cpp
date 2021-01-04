/*
 * author: vongkh
 * created: Sat Jan 02 2021
 */


#include <stdio.h>
#include <cstring>
using namespace std;

constexpr int mxW = 100;
//We need to allocate one extra char that saves "\0" char
char row[mxW + 1];

void solve(){
    int h, w;
    scanf("%d %d", &h, &w);
    for(int i = 0 ; i < h ; i++){
        scanf("%s", row);
        //row[i] appears twice in new_row[2 * i] and new_row[2*i +1]
        printf("%s\n", row);
        printf("%s\n", row);
    }
}

int main(){
    solve();
}
