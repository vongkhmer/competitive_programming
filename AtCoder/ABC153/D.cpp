/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
#include <map>
using namespace std;

uint64_t count_moves(uint64_t h){
    if(h == 1) return 1;
    //we need one move to split the monster
    //then we kill the smaller monster
    return 1 + 2 * count_moves( h / 2);
}
void solve(){
    uint64_t h;
    cin >> h;
    auto ans = count_moves(h);
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
