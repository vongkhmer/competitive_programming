/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int64_t l, r;
int64_t memo[61][2][2][2];

int64_t add_mod(int64_t a, int64_t b){
    int64_t ret = a + b;
    if(ret >= MOD) ret = ret % MOD;
    return ret;
}

int64_t dp(int bit_num, int bigger_than_l, int smaller_than_r, int msb){

    if(bit_num < 0) return 1;

    if(memo[bit_num][bigger_than_l][smaller_than_r][msb] > -1){
        return memo[bit_num][bigger_than_l][smaller_than_r][msb];
    }
    int lb = (l >> bit_num) & 1;
    int rb = (r >> bit_num) & 1;

    int64_t ret = 0;

    // transition 1: x = 1, y = 1
    if( smaller_than_r || rb == 1 ){
        int nl = lb == 0 ? 1 : bigger_than_l;
        int nr = smaller_than_r;
        ret = add_mod(ret, dp(bit_num - 1, nl, nr,1));
    }

    // transition 2: x = 0, y = 0
    if((bigger_than_l || lb == 0)){
        int nl = bigger_than_l;
        int nr = rb == 1 ? 1 : smaller_than_r;
        ret = add_mod(ret, dp(bit_num - 1, nl, nr, msb));
    }

    // transition 3: x = 0, y = 1
    if( (msb > 0) && (bigger_than_l || lb ==0) && (smaller_than_r || rb == 1)){
        int nl = bigger_than_l;
        int nr = smaller_than_r;
        ret = add_mod(ret, dp(bit_num - 1, nl, nr, msb));
    }

    memo[bit_num][bigger_than_l][smaller_than_r][msb] = ret;
    return ret;
}

//This is a hard problem. Comments in my code is not enough
//to explain the solution. I recommend reading the official tutorial

int main(){
    cin >> l >> r;
    for(int i = 0 ; i < 61; i++){
        for(int j = 0 ; j < 2 ; j++){
            for(int k = 0 ; k < 2 ;k++){
                for(int m = 0 ; m < 2 ; m++) memo[i][j][k][m] = -1;
            }
        }
    }
    int64_t ans = dp(60, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
