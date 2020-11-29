/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //straightforward
    cout << a * d - b * c << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
