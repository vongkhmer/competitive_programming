/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 2);
    for(int i = 0 ; i < m ; i++){
        cin >> a[i];
    }
    if( m == 0){
        cout << 1 << endl;
        return;
    }
    //we can add imaginery blue square at position 0 & n + 1 without affecting the result
    //but it make it is easier to handle the corner as we always have the blue square at the corners
    a[m] = 0;
    a[m+1] = n + 1;
    //we need to order the blue square position
    sort(a.begin(), a.end());
    //to use minimum stamp, we need to use the stamp with maximum possible lenth
    //but the length must fit all the white gaps
    //we need to find the minimum non zero gap
    int min_gap = n;
    for(int i = 1 ; i < m + 2 ; i++){
        int white_gap = a[i] - a[i-1] - 1;
        if(white_gap <= 0){
            //there is no gap to be filled
            continue;
        }else{
            min_gap = min(min_gap, white_gap);
        }
    }
    if(min_gap == n){
        //if min_gap is not updated, it means there's no white square
        cout << 0 << endl;
        return;
    }
    int count = 0;
    for(int i = 1; i < m + 2; i++){
        int white_gap = a[i] - a[i-1] - 1;
        if(white_gap <= 0){
            //there is no gap to be filled
            continue;
        }else{
            //the number of stamps need for each gap is ceil(white_gamp /stamp_length)
            count += (white_gap + min_gap - 1 )/ min_gap;
        }
    }
    cout << count << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
