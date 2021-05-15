/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
using namespace std;

void solve(){
    int h, n;
    cin >> h >> n;
    int maximum_damage = 0;
    for(int i = 0 ; i < n ;i++){
        int a;
        cin >> a;
        maximum_damage += a;
    }
    //if our maximum damage output exceeds monster's help
    //we win.
    if(maximum_damage >= h){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
