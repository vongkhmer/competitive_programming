/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    //Just reverse the process by taking turn 
    //restoring the leftmost and rightmost element
    int left_index(0), right_index(n-1);
    bool left = true;
    while(left_index <= right_index){
        if(left){
            cout << a[left_index] << " ";
            left_index++;
        }else{
            cout << a[right_index] << " ";
            right_index--;
        }
        left = !left;
    }
    cout << "\n";
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
