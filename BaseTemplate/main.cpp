#include <bits/stdc++.h>
//#define DEBUG
#define REP(i, nn ) for(int i = 0 ; i < (int) nn; i++)
#define debl(x) std::cout << #x << " " << x << " "; 
#define deb(x) std::cout << #x << " " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template<typename... T>
void read(T& ... a){
    ((cin >> a),...);
}
template<typename... T>
void write(T... a){
    ((cout << a << "\n"),...);
}

template<typename... T>
void write_space(T... a){
    ((cout << a << " "),...);
}

void solve(){
    int n;
    cin >> n;
    vi l(n);
    REP(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1; j < n ; j++){
            for(int k = j + 1 ; k < n ; k++){
                if( l[i] == l[j] || l[j] == l[k] || l[i] == l[k]) continue;
                if( l[i] + l[j] > l[k]){
                    count++;
                }
            }
        }
    }
    cout << count << "\n";
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}

