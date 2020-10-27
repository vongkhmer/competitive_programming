#include <iostream>
using namespace std;

void solve(){
    string number;
    cin >> number;
    for(const auto & digit : number){
        if( digit == '7'){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
