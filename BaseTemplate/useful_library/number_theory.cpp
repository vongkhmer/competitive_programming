#include <iostream>
#include <vector>
namespace VONGCP{
    /** No need to copy namespace *****/

//GCD
//Verified
long long gcd(long long  a, long long b){
    if( a < b) std::swap(a, b);
    if( b == 0) return a;
    return gcd(b, a%b);
}
//LCM
//Verified
long long lcm(long long a, long long b){
    return a * b / gcd(a,b);
}

//Prime Factor
//verified
std::vector<long long> prime_factor(long long a){
    std::vector<long long> ret;
    for(long long i = 2 ; i <= a / i; i++){
        while( a % i == 0){
            ret.push_back(i);
            a /= i;
        }
    }
    if( a > 1) ret.push_back(a);
    return ret;
}


}
