#include <iostream>
#include <vector>
#include <array>
using namespace std;

constexpr int mxN = 200;
int dp[mxN][mxN][mxN];

void update_max(int& a, int b){
    a = max(a, b);
}

void solve(){
    int n, mv;
    cin >> n >> mv;
    string s, t;
    cin >> s >> t;
    const int INF = 1e9;

    for(int i = 0 ; i < mxN; i++){
        for(int j = 0; j < mxN; j++){
            for(int k = 0 ; k < mxN; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    if(s[0] == t[0]){
        dp[0][0][1] = 0;
        dp[0][1][0] = 0;
        dp[0][1][1] = 0;
    }else{
        dp[0][0][0] = 0;
        dp[0][1][0] = 0;
        dp[0][0][1] = 0;
    }
    for(int i = 1; i < n ; i++){
        for(int k = 0 ; k <= i + 1; k++){
            int j = 0;
            dp[i][j][k] = dp[i][j][k-1] + (s[i] == t[0]);
        }
    }

    for(int i = 1 ; i < n; i++){
        for(int j = 1 ; j <= mv; j++){
            for(int k = 0 ; k <= i + 1 ; k++){
                int e0 = (s[i] == t[0]) ? 1 : 0;
                int e1 = (s[i] == t[1]) ? 1 : 0;
                int e2 = (e0 && e1);

                if(e2){
                    update_max(dp[i][j][k], dp[i][j][k-1] + k - 1);
                }else{
                    if(e0){
                        // not changing s[i]
                        update_max(dp[i][j][k], dp[i-1][j][k-1] * 2);
                        //change s[i] to t1 
                        update_max(dp[i][j][k], dp[i - 1][j-1][k] + k - 1);
                    }else if(e1){
                        //not changing s[i]
                        update_max(dp[i][j][k], dp[i - 1][j][k] + k);
                        //change s[i] to t0
                        update_max(dp[i][j][k], dp[i - 1][j-1][k-1]);
                    }else{
                        //no change
                        update_max(dp[i][j][k], dp[i-1][j][k]);
                        //change s[i] to t0
                        update_max(dp[i][j][k], dp[i-1][j-1][k-1]);
                        //change s[i] to t1
                        update_max(dp[i][j][k], dp[i-1][j-1][k] + k);
                    }
                }
                printf("i %d j %d k %d dp %d\n", i , j , k , dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    for(int j = 0 ; j <= mv ; j++){
        for(int k = 0 ; k <= n ; k++){
            update_max(ans, dp[n-1][j][k]);
        }
    }
    cout << ans << "\n";
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}
