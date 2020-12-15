/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */

#include <iostream>
using namespace std;

void solve(){
    //Takahashi has at most 100 problems
    int ans = 100;	
    for(int i = 0 ; i < 4 ; i++){
        int a;
        cin >> a;
        //He cannot create contests more than the number of the problem he has
        ans = min(ans, a);
    }
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
