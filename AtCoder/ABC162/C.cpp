#include <iostream>
using namespace std;

int my_gcd(int a, int b){
    //C++ STL also provides implementation of gcd
    //check it out

    if(a < b){
        swap(a,b);
    }
    if( b == 0){
        return a;
    }
    return my_gcd(b, a % b);
}

int gcd3(int a, int b, int c){
    int gcd_a_b = my_gcd(a,b);
    // gcd has commutative property
    return my_gcd(gcd_a_b, c);
}

void solve(){
    int k;
    cin >> k;
    // since k is small and gcd can be computed with O(logN)
    // we can use brute force
    int sum = 0;
    for(int a = 1 ; a <= k ; a++){
        for(int b = 1; b <= k ; b++){
            for(int c = 1 ; c <= k ; c++){
                sum += gcd3(a, b, c);
            }
        }
    }
    cout << sum << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}