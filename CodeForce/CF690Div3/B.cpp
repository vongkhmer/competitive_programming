/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string target = "2020";
    //left_match : how many characater from the leftmost that matches 2020
    //right_match : from the rightmost
    int left_match = 0, right_match = 0;
    for(int i = 0 ; i < target.size() ; i++){
        if(target[i] == s[i]){
            left_match++;
        }else{
            break;
        }
    }
    for(int i = 0; i < target.size() ; i++){
        if(target[target.size() - 1 - i] == s[n-1-i] ){
            right_match++;
        }else{
            break;
        }
    }
    //if the total match is more than target size, we can have the target string
    if(left_match + right_match >= target.size()){
        cout << "Yes\n";
    }else{
        cout << "No\n";
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
