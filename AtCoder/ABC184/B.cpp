/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
using namespace std;

void solve(){
    long long n , x;
    cin >> n >> x;
    string s;
    cin >> s;
    //straightforward
    for(char c : s){
        if( c == 'o'){
            x++;
        }else{
            x--;
            x = x < 0 ? 0 : x;
        }
    }
    cout << x << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
