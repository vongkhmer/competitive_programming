/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0 ; i < n ; i++) cin >> h[i];
    //we use greedy algorithm; we use special move on monster with 
    //biggest health point
    sort(h.begin(), h.end());
    long long ans = 0;
    for(int i = 0 ; i < n - k ; i++) ans += h[i];
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
