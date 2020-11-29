/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(){
    int n;
    long long t;
    cin >> n>> t;
    vector<long long> a(n);
    // this problem is NP-complete and its solution is well-known
    // as the "subset sum problem"
    // we can only  use "meet in the middle" technique to solve this problem for small n
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    int left = n / 2;
    int right = n - left;
    set<long long> ls, rs;
    int state = 0;
    while(state < (1<<left)){
        long long sum = 0;
        for(int i = 0 ; i < left ; i++){
            if( state & (1<<i)){
                sum += a[i];
            }
        }
        ls.insert(sum);
        state++;
    }
    state = 0;
    while(state < (1<<right)){
        long long sum = 0;
        for(int i = left ; i< n ;i++){
            if( state & (1<<(i-left))){
                sum += a[i];
            }
        }
        rs.insert(sum);
        state++;
    }
    long long ans = 0;
    for(auto sum : ls){
        if(sum > t) break;
        auto it = rs.lower_bound(t -  sum + 1);
        int sum2 = 0;
        if( it != rs.begin()){
            it--;
            sum2 = *it;
        }
        ans = max(ans, sum + sum2);
    }
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
    return 0;
}
