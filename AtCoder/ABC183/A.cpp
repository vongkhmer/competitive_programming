/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */

#include <iostream>
using namespace std;

int relu(int x){
    if( x < 0) return 0;
    else return x;
}
void solve(){
    int x;
    cin >> x;

    cout << relu(x) << endl; 
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
