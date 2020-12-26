/*
 * author: vongkh
 * created: Sat Dec 26 2020
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int mxN = (int)1e5 + 100;
int64_t MOD = (int64_t) 1e9 + 7;
int64_t factorial[mxN + 1], inverse_factorial[mxN + 1];

int64_t mod_pow(int64_t a, int p){
    if( p == 0) return 1;
    int64_t ans = mod_pow(a, p / 2);
    ans = ans * ans;
    if(ans >= MOD) ans = ans % MOD;
    if( p % 2 > 0) ans = ans * a;
    if(ans >= MOD) ans = ans % MOD;
    return ans;
}

void calculate_factorial(){
    factorial[0] = 1;
    for(int i = 1 ; i <= mxN ; i++){
        factorial[i] = factorial[i-1] * i;
        if(factorial[i] >= MOD) factorial[i] = (factorial[i] % MOD);
    }
    //Fermat's little theorem
    inverse_factorial[mxN] = mod_pow(factorial[mxN], MOD - 2);
    for(int i = mxN - 1 ; i >= 0 ; i--){
        inverse_factorial[i] = inverse_factorial[i+1] * (i+1);
        if(inverse_factorial[i] >= MOD){
            inverse_factorial[i] = (inverse_factorial[i] % MOD);
        }
    }
}

int64_t nCr(int n, int r){
    int64_t ans = factorial[n];
    ans = ans * inverse_factorial[r];
    if(ans >= MOD) ans = ans % MOD;
    ans = ans * inverse_factorial[n-r];
    if(ans >= MOD) ans = ans % MOD;
    return ans;
}

void solve(){
   int64_t n, m; 
   scanf("%lld %lld", &n , &m);
   //since a1 * ... * an = m 
   // the sequenc must contains number composed from primes that divides m
   // Hence, the total number of the squence == the number of ways we distribute those primes to a1, ..., an

   //power stores the power of the composite primes
   vector<int> power;
   //prime factorization
   for(int64_t i = 2 ; i <= m / i ; i++){
       int p = 0;
       while( m % i == 0){
           p++;
           m /= i;
       }
       if(p > 0){
           power.push_back(p);
       }
   }
   if( m > 1){
       power.push_back(1);
   }

   int64_t ans = 1;
   for(int p : power){
       //Each prime can be distribute independently
       // the number of ways to distribute p primes to n slot is nCr(n-1 + p, p). (reference "stars and bars")
       ans = ans * nCr(n - 1 + p , p);
       if( ans >= MOD) ans = ans % MOD;
   }
   printf("%lld\n", ans);
}

int main(){
    //calculate all factorial and its modular reverse
    calculate_factorial();
    solve();
    return 0;
}
