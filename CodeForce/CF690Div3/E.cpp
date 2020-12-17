/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int mxN = (int)2e5;
constexpr int64_t MOD = (int64_t)1e9 + 7;

//factorial result to calculate nCr
int64_t factorial[mxN+1];
int64_t inverse_factorial[mxN+1];

//modular add
int64_t mod_add(int64_t a , int64_t b){
    int64_t ans = a + b;
    if(ans >= MOD){
        ans = ans % MOD;
    }
    return ans;
}
//modular multiplication
int64_t mod_mul(int64_t a, int64_t b){
    int64_t ans = a * b;
    if(ans >= MOD){
        ans = ans % MOD;
    }
    return ans;
}
//modular power
int64_t mod_pow(int64_t a, int p){
    if(p==0) return 1;
    int64_t ret = mod_pow(a, p / 2);
    ret = mod_mul(ret, ret);
    if( p % 2 > 0){
        ret = mod_mul(ret, a);
    }
    return ret;
}
// calculate factorial once and save the result to use later
void cal_factorial(){
    factorial[0] = 1;
    for(int i = 1 ; i <= mxN ; i++){
        factorial[i] = mod_mul(factorial[i-1], i);
    }
    inverse_factorial[mxN] = mod_pow(factorial[mxN], MOD - 2);
    for(int i = mxN - 1 ; i >= 0 ; i--){
        inverse_factorial[i] = mod_mul(inverse_factorial[i+1], i + 1);
    }
}
// calculation combination
int64_t nCr(int n, int r){
    int64_t res = factorial[n];
    res = mod_mul(res, inverse_factorial[r]);
    res = mod_mul(res, inverse_factorial[n-r]);
    return res;
}

void solve(){
    int n;
    cin >> n;
    int m = 3, k = 2;
    //for E1 comment out the next line
    cin >> m >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    //First observation: we can sort the array and the answer stay the same
    sort(a.begin(), a.end());
    int i = 0, j = 0;
    int64_t count = 0;
    //Second observation: we can fixed i and count how many j, z that satisfies
    for( ; i < n ; i++){
        for( ; j < n ; j++){
            // min(ai, .., az) = ai && max(ai, ..., az) = z
            //hence, requirements <==> a[j] - a[i] <= k
            if(a[j] - a[i] > k) break;
        }
        int can_choose = j - i - 1;
        if(can_choose >= m - 1){
            //the number of turple is the the diffrent ways we can pick j..z from the elements 
            //that we can choose
            count = mod_add(count, nCr(can_choose, m - 1));
        }
    }
    cout << count << "\n";
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    cal_factorial();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
