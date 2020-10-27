#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    // n is big
    // we should use long long type to store sum
    long long sum = 0;
    for(int i = 1 ; i <= n ; i++){
        if( i % 3 == 0 || i % 5 == 0){
            continue;
        }else{
            sum += i;
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
