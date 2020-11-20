/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
using namespace std;

constexpr int MOD = 1e9+7;
int modular_add(int a, int b){
    assert( a >= 0 && a < MOD && b >=0 && b < MOD);
    int ans = a + b;
    if(ans >= MOD){
        ans = ans % MOD;
    }
    return ans;
}
void solve(){
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0 ; i < h ; i++){
        cin >> grid[i];
        assert(w == (int) grid[i].size());
    }
    //dp[i][j][0] : number of way to move from (i,j) to goal with first move right
    //dp[i][j][1], dp[i][j][2] :  same, but first move down, diagonal
    //dp[i][j][3] : total

    vector<vector<array<int,4>>> dp(h, vector<array<int,4>>(w));
   
    for(int i = h - 1; i >= 0 ; i--){
        for(int j = w - 1; j >= 0 ; j--){                
            //if it's a block, we cannot move
            if(grid[i][j] == '#') continue;
            //special case goal: we don't have to move in anydirection
            if(i == h - 1 && j == w -1){
                
                dp[i][j] = {0, 0, 0, 1};
                continue;
            } 
            //try moving right
            if(j + 1 < w ){
                //we can either move to (i, j+ 1) frist or pass through it in the right direction
                dp[i][j][0] = modular_add(dp[i][j+1][3], dp[i][j+1][0]);
            }
            //try moving down
            if( i + 1 < h){
                //we can either move to (i+ 1, j) frist or pass through it in the downward direction
                dp[i][j][1] = modular_add(dp[i+1][j][3], dp[i+1][j][1]);
            }
            //try moving diagonal
            if( i + 1 < h && j + 1 < w){
                //we can either move to (i+ 1, j + 1) frist or pass through it in the diagonal direction
                dp[i][j][2] = modular_add(dp[i+1][j+1][3], dp[i+1][j+1][2]);
            }
            //finally, we count the total way
            dp[i][j][3] = modular_add(dp[i][j][0], modular_add(dp[i][j][1], dp[i][j][2]));
            
        }
    }
    cout << dp[0][0][3] << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
