/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    int INF = 1e8;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i] >> b[i];
    }
    //use dp[i] minimum magic point to defeat monster with health i
    vector<int> dp(h+1, INF);
    dp[0] = 0;

    for(int k = 1 ; k <= h ; k++){
        for(int i = 0 ; i < n ; i++){
            if(a[i] >= k){
                //we can use b[i] to defeat the monster
                dp[k] = min(dp[k], b[i]);
            }else{
                // or we use b[i] to reduce the health of monster
                dp[k] = min(dp[k], dp[k-a[i]] + b[i]);
            }
        }
    }
    cout << dp[h] << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
