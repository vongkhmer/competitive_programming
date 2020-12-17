/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int x;
    cin >> x;
    vector<int> res;
    //greedy works because if the one answer is "abcd"
    //then "(a-1)bc(d+1)" is the better answer
    //which means that taking d as big as possible is the optimal solution
    for(int i = 9 ; i > 0 ; i--){
        if( x >= i){
            res.push_back(i);
            x -= i;
        }
    }
    if( x > 0){
        cout << "-1\n";
    }else{
        for(int i = res.size() - 1 ; i >= 0 ; i--){
            cout << res[i];
        }
        cout << "\n";
    }
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
