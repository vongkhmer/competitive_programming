/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
using namespace std;

void solve(){
    int h, a;
    cin >> h >> a;
    // answer = ceil(h/a)
    int ans = (h + a - 1) / a;
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
