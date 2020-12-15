/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */

#include <iostream>
using namespace std;

int64_t nCr(int64_t n, int64_t r){
    int64_t ret = 1;
    // nCr = n * (n - 1) * ( n- 2) * .. * (n-(r-1)) /( 1 * 2 * .. * r)
    for(int64_t k = 1; k <= r; k++){
        ret *= (n + 1 - k);
        ret /= k;
    }
    return ret;
}
void solve(){
    int64_t l;
    cin >> l;
    // the division can be considered as the way to choose 11 cutting points between 1 ... l -1
    //Hence, the answer is nCr(l-1, 11)
    cout << nCr(l - 1, 11) << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
