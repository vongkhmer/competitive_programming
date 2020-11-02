#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    //we need to store the activeness along with its original index
    //because we are going to sort this array
    vector<pair<long long, long long>> a;
    a.reserve(n);
    for(int i = 0 ; i < n ; i++){
        long long activess;
        scanf("%lld", &activess);
        a.push_back(make_pair(activess, (long long) i));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    //dp[l][r] maximum total happiness achieved from l+r bigest elements
    // Among those, l are placed left and r are placed right
    // we can prove that switching position of the max element with another nearer to the edge
    // can never decrease the the sum. Hence, this dp works.
    vector<vector<long long>> dp(n + 1, vector<long long>(n+1));
    long long ans = 0;
    for(int l = 0 ; l <= n ; l++){
        for(int r = 0 ; r <= n ; r++){
            if(l + r > n) break;
            long long least_active = a[l+r - 1].first;
            long long original_ind = a[l+r - 1].second;
            if(l > 0){
                //the least active enfant can be placed at position (l - 1)
                dp[l][r] = max(dp[l][r], dp[l-1][r] + least_active * abs(original_ind - (l - 1)));
            }
            if(r > 0){
                //the least active enfant can be placed at position (n - r)
                dp[l][r] = max(dp[l][r], dp[l][r-1] + least_active * abs(original_ind -  (n - r)));
            }
            if(l + r == n){
                ans = max(ans, dp[l][r]);
            }
        }
    } 
    printf("%lld \n", ans);
}

int main(){
    solve();
}
