#include <iostream>
#include <vector>
using namespace std;

void solve(){
    //Getting input
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    //using dp to solve this problem
    // upper is the sum of ceil(n/2) terms , lower is the sum of floor(n/2) terms
    vector<long long> max_sum_upper(n), max_sum_lower(n);
    max_sum_upper[0] = a[0];
    max_sum_lower[1] = max(a[0], a[1]);
    max_sum_upper[1] = max_sum_lower[1];

    for(int i = 2 ; i < n ; i++){
        //if we don't choose a[i], we need to choose extra term in 1..i-1
        max_sum_lower[i] = max(a[i] + max_sum_lower[i-2], max_sum_upper[i-1]);
        if(i % 2 == 1){
            //if the number of element is even, upper sum and lower sum are the same
            max_sum_upper[i] = max_sum_lower[i];
        }else{
            //if the number of element is odd, we need to choose a[i] to have enough element
            max_sum_upper[i] = a[i] + max_sum_upper[i-2];
        }
    }
    
    cout << max_sum_lower[n-1] << endl;

}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
