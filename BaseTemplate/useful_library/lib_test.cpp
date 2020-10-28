#include <iostream>
#include <random>
#include <algorithm>
#include "number_theory.cpp"
#include "combinatorial.cpp"
#include <stdio.h>
#include <numeric>
using namespace std;
using namespace VONGCP;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

long long fact(int n){
    long long ans = 1;
    for(int i = 1; i <= n ; i++){
        ans *= i;
    }
    return ans;
}

long long combine(int n, int r){
    long long ans = fact(n);
    ans /= (fact(r) * fact(n-r));
    return ans;
}

int main(){
    //test prime factor
    srand(69);
    combinatorial combi(1e5);
    bool err = false;
    for(int n = 0 ; n <= 20 ; n++){
        for(int r = 0 ; r <= n; r++){
            long long c1 = combine(n, r);
            long long c2 = combi.C(n, r);
            if( c1 != c2){
                printf("Error @ n %d r % d expected %lld got %lld\n",
                n, r, c1, c2);
                err = true;
                break;
            }
            printf("n %d r %d ==> C %lld %lld\n", n, r, c1, c2 );
        }
        if(err) break;
    }


    return 0;
}
