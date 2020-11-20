/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>     
using namespace std;

void solve(){
    int n;
    long long w;
    cin >> n >> w;
    vector<pair<long, long>> start(n), stop(n);
    for(int i = 0 ; i < n ; i++){
        long long s , t, p;
        cin >> s >> t >> p;
        start[i] = make_pair(s, p);
        stop[i] = make_pair(t, p);
    }
    sort(start.begin(), start.end());
    sort(stop.begin(), stop.end());
    vector<long long> use(n), ret(n);
    use[0] = start[0].second;
    ret[0] = stop[0].second;
    for(int i = 1 ; i < n ; i++){
        use[i] = start[i].second + use[i-1];
        ret[i] = stop[i].second + ret[i-1]; 
    }

    // shortage only happens at the moment someone new comes
    // and the overall usage exceeds limit
    long current_usage = 0;
    for(int i = 0 ; i < n ;i++){
        //check how many people stopped using water
        auto it = lower_bound(stop.begin(), stop.end(), make_pair(start[i].first + 1, 0L));
        if( it != stop.begin()){
            it--;
            int ind = distance(stop.begin(), it);
            //current usage : active_usage = all_usage - stopped_usage
            current_usage = use[i] - ret[ind];
        }else{
            //No inactive usage at this moment
            current_usage = use[i];
        }

        //check if the current usage exceeds the limit
        if(current_usage > w){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
