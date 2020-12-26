/*
 * author: vongkh
 * created: Sat Dec 26 2020
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

void get_border(int& border, int city_num, int dir){
    //dir = 1 ==> right border, dir = -1 ==> left border
    for(int i = 0 ; i < city_num ; i++){
        int tmp;
        scanf("%d", &tmp);
        border = (dir * tmp > dir * border) ? tmp : border;
    }
}

void solve(){
    int n, m , x , y;
    scanf("%d %d %d %d",&n, &m, &x, &y);
    int x_border = x, y_border = y;
    //get x's right border
    get_border(x_border, n, 1);
    //get y's left border
    get_border(y_border, m, -1);
    //if x's territory and y's territory overlapse ==> we have ward
    const char* ans = (x_border >= y_border) ? "War" : "No War";
    printf("%s\n", ans);
}

int main(){
    solve();
}
