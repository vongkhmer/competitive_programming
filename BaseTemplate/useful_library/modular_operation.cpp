#include <iostream>

namespace VONGCP{
   /** No need to copy namespace *****/

// it is safer to use long long if 
// you use multiplication

constexpr long long MOD = 1e9+7;

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

}