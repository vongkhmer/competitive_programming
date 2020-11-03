#include <iostream>
using namespace std;

void solve(){
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    // ans = p * q with p >= x and q >= y
    // (p + 1) * ( q - 1) = pq + q - p  -1
    // if p < q, we can decrease it some more
    //Hence, minimum happens at boundary p = x or q = y
    long long boundary_a = max(x, a - n);
    long long ans1 = boundary_a * max(y, b - (n - (a - boundary_a)));

    long long boundary_b = max(y, b - n);
    long long ans2 = boundary_b * max(x, a - (n - (b - boundary_b)));

    cout << min(ans1, ans2) << endl;
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
