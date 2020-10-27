#include <iostream>
#include <cassert>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    assert(n == s.size());
    int num_r = 0, num_g = 0, num_b = 0;
    for(const auto& ch : s){
        switch (ch)
        {
        case 'R':
            num_r++;
            break;
        case 'G':
            num_g++;
            break; 
        case 'B':
            num_b++;
            break;
        default:
            assert(false);
            break;
        }
    }
    //all RGB turple including (j - i == k - j)-turples
    long long total_combination = (long long) num_r * (long long) num_g * (long long) num_b;

    //now we need to substract the turple that satisfies j - i == k - j
    long long ans = total_combination;

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(s[i] == s[j]) continue;
            int k = 2 * j - i;
            if( k < n && s[k] != s[i] && s[k] != s[j]){
                ans--;
            }
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
