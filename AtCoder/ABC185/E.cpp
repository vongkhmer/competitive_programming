/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    //we use dynamic programming to solve this problem
    //dp[i][j] answer for the case a[0-i] & b[0:j]
    vector<vector<int>> dp(n, vector<int>(m));
    //initialize dp[0][0]
    dp[0][0] = (a[0] == b[0]) ? 0 : 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ;j++){
            //it is already initialize
            if(i == 0 && j == 0) continue;

            if(i == 0){
                // answer for a[0] with b[0:j]
                if(a[i] == b[j]){
                    //we only need to delete b[0] .. b[j-1] 
                    dp[i][j] = j;
                }else{
                    //we can delete b[j]
                    dp[i][j] = 1 + dp[i][j-1];
                }
            }

            if(j == 0){
                //same way of thinking as i = 0
                if(a[i] == b[j]){
                    dp[i][j] = i;
                }else{
                    dp[i][j] = 1 + dp[i-1][j];
                }
            }

            if( i > 0 && j > 0){
                if(a[i] == b[j]){
                    //we keep a[i] & b[j], and consider the rest
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    //we have 3 choices: keep a[i],b[j] or delete a[i] or delete b[j]
                    dp[i][j] = 1 + dp[i-1][j-1];
                    dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[n-1][m-1] << endl;

}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
