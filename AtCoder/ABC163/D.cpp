#include <stdio.h>
using namespace std;

const long long MOD = 1e9+7;

long long sum(long long n){
    // return 1 + 2 + ... + n
    long long ans = n * ( n + 1) / 2; 
    return ans;
}

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    long long count = 0;

    for(int i = k ; i <= n + 1 ; i++){
        // sum from 0 to i - 1
        long long min_offset = sum(i-1); 
        //sum from n - i + 1 to n
        long long max_offset = sum(n) - sum(n - i);
        count = count + (max_offset - min_offset + 1); 
        if(count >= MOD){
            count = count % MOD;
        }
    }
    printf("%lld \n", count);
}

int main(){
    solve();
    return 0;
}
