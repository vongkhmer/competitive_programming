/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<vector<long long>> t(n, vector<long long>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> t[i][j];
        }
    }
    //middle_path : cities to visit between first city (in order)
    vector<int> middle_path(n-1);
    for(int i = 0 ; i < n - 1 ; i++){
        middle_path[i] = i + 1;
    }
    int count = 0;
    //we can do brute force on all possible permutation because n is small
    do{
        long long time = 0; 
        //start from city 1
        int cur_city = 0;
        for(int i = 0 ; i < n - 1; i++){
            //go through all city in between
            time += t[cur_city][middle_path[i]];
            cur_city = middle_path[i];
        }
        //go back to city 1
        time += t[cur_city][0];
        if(time == k){
            count++;
        }

    }while(next_permutation(middle_path.begin(), middle_path.end()));
    cout << count << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
