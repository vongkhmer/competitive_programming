/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */

#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;

void solve(){
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double px, py;
    py = 0;
    //incident angle ( relative to surface mus the same)
    //Hence, its tangent must be the same. ie. sy / ( px - sx) = gy / (gx - px) 
    px = ( sx * gy  + gx * sy) / (sy + gy); 
    cout << std::fixed << setprecision(10);
    cout << px << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
