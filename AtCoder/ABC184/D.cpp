/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
using namespace std;

constexpr int mxN = 101;
//dp[i][j][k] expected value of number of operation
double dp[mxN][mxN][mxN];
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 99 ; i >= 0; i--){
        for(int j = 99; j >= 0; j--){
            for(int k = 99; k >= 0 ; k--){
                double pa, pb, pc;
                //there are 3 possible trasition
                // increment a with pa probabilaty, b with pb and c with pc
                pa = 1.0 * i / ( i + j + k);
                pb = 1.0 * j /( i + j + k);
                pc = 1.0 * k / (i + j + k);
                //definition of expected value
                dp[i][j][k] = 1 + pa * dp[i+1][j][k] + pb * dp[i][j+1][k] + pc * dp[i][j][k+1];
            }
        }
    }
    printf("%.9f\n", dp[a][b][c]);
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
    return 0;
}
