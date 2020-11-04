#include <iostream>
#include <vector>
#include <array>
using namespace std;

constexpr int mxN = 201;
//dp[i][j][k] : maximum appearance of t in s[0..i] using no more than j moves
//while having k appearance of t[0]
// dp[i][j][k] = -1 if such case is impossible 
int dp[mxN][mxN][mxN];
string s, t;

void umax(int& a, int b){
    //update value of a if b > a
    a = max(a, b);
}

int cal(int i, int j, int k){
    //i , j , k cannot be negative
    if( i < 0 || j < 0 || k < 0) return -1;
    // it is impossible to appearance more than the total character
    if( k > i + 1) return -1;
    //if calculated, just return the result
    if( dp[i][j][k] > -1e9) return dp[i][j][k];

    int ans = -1; 

    if(s[i] == t[1]){
        int e = (t[1] == t[0]) ? 1 : 0;

        int no_update_prev_state = cal(i-1, j , k - e) ; 
        if( no_update_prev_state > - 1){
            //no update, use it now
            umax(ans, no_update_prev_state  + k - e);        
        }
        
        int update_t0_prev_state = cal(i-1, j - 1 + e , k - 1);
        if( update_t0_prev_state > -1){
            //update s[i] to t[0], for future use
            umax(ans, update_t0_prev_state + e*(k-1));
        }
    }else if( s[i] == t[0]){
        // no update = keep it for future use
        int no_update_prev_state = cal(i - 1, j, k - 1);
        if(no_update_prev_state > -1){
            umax(ans, no_update_prev_state);
        }
        //update to t[1], use it now
        int update_t1_prev_state = cal(i - 1, j - 1, k);
        if( update_t1_prev_state > -1){
            umax(ans, update_t1_prev_state + k);
        }
    }else{
        int e = (t[0] == t[1]) ? 1 : 0;
        //no update
        int no_update_prev_state = cal(i - 1, j, k);
        umax(ans, no_update_prev_state); 

        //update to t[0]
        int update_t0_prev_state = cal(i - 1, j - 1, k - 1);
        if( update_t0_prev_state > -1){
            umax(ans, update_t0_prev_state + e *( k - 1));
        }

        //update to t[1]
        int update_t1_prev_state = cal(i - 1, j - 1, k -e);
        if(update_t1_prev_state  > -1){
            umax(ans, update_t1_prev_state + k - e);
        }
    }

    dp[i][j][k] = ans;
    return ans;
}

void solve(){
    int n, mv;
    cin >> n >> mv;
    cin >> s >> t;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= mv; j++){
            for(int k = 0 ; k <= i + 1 ; k++){
                //-1e9 means not yet calculated
                dp[i][j][k] = -1e9;
            }
        }
    }
    int e = (s[0] != t[0]) ? 1 : 0;
    // -1 means impossible
    dp[0][0][e] = -1;

    int ans = 0;
    for(int k = 0 ; k <= n ; k++){
        umax(ans, cal(n-1, mv, k));
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
