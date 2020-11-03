#include <iostream>
using namespace std;

void solve(){
    long long a ,b ;
    cin >> a >> b;
    auto dist = abs(a - b);
    //the optimal move is the move that reduces distance AB
    long long num_move = dist / 10;
    if(dist % 10 != 0){
        // we have one more move to do
        num_move++;
    }
    cout << num_move << "\n";
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
