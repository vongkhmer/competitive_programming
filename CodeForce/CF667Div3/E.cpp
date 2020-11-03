#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> x(n);
    for(int i = 0 ; i < n ; i++){
        cin >> x[i];
    }
    //Actually we don't need y in this problem
    vector<long long> y(n);
    for(int i = 0 ; i < n ; i++){
        cin >> y[i];
    }
    // We need to sort the vector to be able to use binary sort
    sort(x.begin(), x.end());
    //can_save[i] store the maximum number of points a platform can save
    //if it is to be placed at a position between i and n
    vector<int> can_save(n + 1);
    for(int i = n - 1 ; i >= 0; i--){
        long long right_bound = x[i] + k;
        auto it = lower_bound(x.begin(), x.end(), right_bound + 1);
        it--;
        int save_points = distance(x.begin(), it) - i + 1;
        can_save[i] = max(save_points, can_save[i+1]); 
    }
    // the maximum number of points that two platform can save
    int max_save = 0;
    for(int i = 0 ; i < n ; i++){
        //we place the first platform at x[i]
        long long right_bound = x[i] + k;
        auto it = lower_bound(x.begin(), x.end(), right_bound + 1);
        it--;
        int save_points = distance(x.begin(), it) - i + 1;

        //Next we add the maximum number of points that the second platform can save
        it++;
        int next_pos = distance(x.begin(), it);
        save_points += can_save[next_pos];
        //update the maximum number
        max_save = max(max_save, save_points);
    }
    cout << max_save << "\n";

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
