/*
 * author: vongkh
 * created: Fri May 14 2021
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve(){
    int n;
    int64_t d, a;
    cin >> n >> d >> a;
    vector<pair<int64_t, int64_t>> monsters(n);
    for(int i = 0 ; i < n ; i++){
        cin >> monsters[i].first >> monsters[i].second;
    }
    //Observation: suppose the left-most monster has health h 
    // we need damage from at least ceil(h/a) bombs to kill the monster
    // In addition, we only need the bomb do deal damage at its left edge
    // This is the optimal way because we can always arrange it to be like this without needing more bomb
    sort(monsters.begin(), monsters.end());
    //we use queue to store the range which a bomb deals damage
    queue<pair<int64_t, int64_t>> qu;
    int64_t sum = 0;
    int64_t ans = 0;
    for(auto [x, h] : monsters){
        while(qu.size()){
            auto [y, r] = qu.front();
            //if the range of previous bomb does not reach x
            //the health of the monster is not affected
            if(y < x){
                sum -= r;
                qu.pop();
            }else{
                break;
            }
        }
        h -= sum;
        if(h > 0){
            int64_t bomb = (h + a - 1) /a;
            ans += bomb;
            int64_t damage = bomb * a;
            qu.push({x + 2 * d, damage});
            sum += damage;
        }
    }
    cout << ans << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
