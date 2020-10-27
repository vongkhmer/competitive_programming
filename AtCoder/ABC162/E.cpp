#include <iostream>
#include <vector>
using namespace std;

constexpr long long MOD = 1e9+7;

//ModNum struct deals with modular operation
//Creating this kind of struct helps improve your code quality
template <typename T>
struct ModNum{
    T n;

    ModNum() : n(0) {}

    ModNum(T n_)  {
        n = n_;
        if(abs(n) >= MOD){
            n = n % MOD;
        }
        if(n < 0){
                n = MOD + n;
        }
    }

    ModNum operator+ (const ModNum& rhs){
        T ret = this->n + rhs.n;
        return ModNum(ret);
    }

    ModNum operator- (const ModNum& rhs){
        T ret = this->n - rhs.n + MOD;
        return ModNum(ret); 
    }

    ModNum operator* (const ModNum& rhs){
        T ret = this->n * rhs.n; 
        return ModNum(ret); 
    }

    ModNum pow(T p) const {
        if(p < 1) return ModNum((T)1);
        ModNum a = this->pow(p/2);
        auto ret = a * a;
        if(p%2) ret = ret * (*this);
        return ret;
    }

    ModNum operator/(const ModNum& rhs){
        auto inverseMod = rhs.pow(MOD - 2);
        return (*this) * inverseMod;
    }

    friend std::ostream& operator<< (std::ostream& os, const ModNum& m){
        os << m.n;
        return os;
    } 
};

typedef ModNum<long long> modular_num;

void solve(){
    int n, k;
    cin >> n >> k;

    //num_turple_with_gcd[i] = number of turples with gcd equal to 
    vector<modular_num> num_turple_with_gcd(k+1);
    // only turple (k, k, ... , k) has gcd equal to k
    num_turple_with_gcd[k] = 1;

    for(int g = k - 1 ; g >= 1; g--){
        modular_num multiple_of_g = k / g;
        modular_num num_turple_multiple_of_g = multiple_of_g.pow(n);

        num_turple_with_gcd[g] = num_turple_multiple_of_g;

        //since we included the turples with gcd not exactly equal to g
        // but equal to a multiple of g, we need to substract these away
        for(int i = 2; g * i <= k ; i++){
            num_turple_with_gcd[g] = num_turple_with_gcd[g] - num_turple_with_gcd[g*i];
        }
    }
    //finally, the answer is sum of (num_turple_with_gcd_g * g)
    modular_num ans = modular_num(0);
    for(int g = 1; g <= k ; g++){
        ans = ans + num_turple_with_gcd[g] * g; 
    }
    cout << ans << endl;

}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
