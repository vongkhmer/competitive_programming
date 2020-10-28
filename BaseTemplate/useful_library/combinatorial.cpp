#include <vector>

namespace VONGCP{

constexpr long long MOD = 1e9+7;
struct combinatorial
{
    int mxN;
    std::vector<long long> factorial_mod;
    std::vector<long long> inverse_factorial_mod;

    combinatorial(int n){
        mxN = n;
        factorial_mod = std::vector<long long>(n + 1);
        inverse_factorial_mod = std::vector<long long>(n + 1);
        cal_facto_mod();
        cal_inverse_facto_mod();
    }

    void cal_facto_mod(){
        factorial_mod[0] = 1;
        long long ans = factorial_mod[0];
        for(int i = 1 ; i <= mxN ; i++){
            ans = ans * i ;
            if( ans >= MOD){
                ans = ans % MOD;
            }
            factorial_mod[i] = ans;
        }
    }

    long long pow_mod(long long a , long long p){
        if(p < 1) return (long long) 1;
        auto ret = pow_mod(a, p/2);
        ret = ret * ret;
        if(ret >= MOD) ret = ret % MOD;
        if(p%2) ret = ret * a;
        if(ret >= MOD) ret = ret % MOD;
        return ret;
    }

    void cal_inverse_facto_mod(){
        long long last_factor = pow_mod(factorial_mod[mxN], MOD - 2);
        inverse_factorial_mod[mxN] = last_factor;
        for(int i = mxN -1 ; i >= 0; i--){
            last_factor = last_factor * ( i + 1);
            if( last_factor >= MOD){
                last_factor = last_factor % MOD;
            }
            inverse_factorial_mod[i] = last_factor;
        }
    }

    long long C(long long n,long long r){
        long long ans = factorial_mod[n] * inverse_factorial_mod[r];
        if( ans >= MOD){
            ans = ans % MOD;
        }
        ans = ans * inverse_factorial_mod[n - r];
        if(ans >= MOD){
            ans = ans % MOD;
        }
        return ans;
    }

};
    
}