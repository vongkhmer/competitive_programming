/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */
#include <iostream>
using namespace std;

void solve(){
    int64_t n, m ,t;
    cin >> n >> m >> t;
    //last charge at min 0 with maximum battery
    int64_t current_battery = n;
    int64_t last_charge = 0;
    for(int i = 0 ; i < m ; i++){
        int64_t arrive, leave;
        cin >> arrive >> leave;
        //Before charging
        current_battery -= (arrive - last_charge);
        if(current_battery <= 0){
            cout << "No" << endl;
            return;
        }
        //start charging
        current_battery += (leave - arrive);
        //The battery can never go over its capacity
        if(current_battery > n){
            current_battery = n;
        }
        last_charge = leave;
    }
    //final check if he can arrive home safely
    current_battery -= (t - last_charge);
    if(current_battery <= 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
