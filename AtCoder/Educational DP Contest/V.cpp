#include <bits/stdc++.h>
#define REP(i, nn ) for(int i = 0 ; i < (int) nn; i++)
#define REPS(i, ss, nn ) for(int i = ss ; i < (int) nn; i++)
#define REV(i, ss, nn ) for(int i = ss ; i >= nn; i--)
#define deb(x) std::cout << #x << " " << x << endl;
#define debl(x) std::cout << #x << " " << x << " ";
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
namespace std{
    template<class Fun>
    class y_combinator_result{
        Fun fun_;
        public:
            template<class T>
            explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)){}
            template<class ...Args>
            decltype(auto) operator()(Args&&...args){
                return fun_(std::ref(*this), std::forward<Args>(args)...);
            }
    };
    template<class Fun>
    decltype(auto) y_combinator(Fun && fun){
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }
};
template<typename T>
bool umax(T& a, T b){
    bool ret = a < b;
    if(ret) a = b;
    return ret;
}
template<typename T>
bool umin(T& a, T b){
    bool ret = a > b;
    if(ret) a = b;
    return ret;
}
struct edge{
    int to; ll cost;
    int from;
    edge(){ edge(0,0);}
    edge(int to_, ll cost_) : to(to_), cost(cost_){}
    edge(int to_, int from_, ll cost_) : to(to_), cost(cost_), from(from_){}
};

template<typename... T>
void read(T& ... a){
    ((cin >> a),...);
}

template<typename... T>
void write(T... a){
    ((cout << a),...);
}


template<typename T>
vector<T> read_array(int sz){
    vector<T> ret(sz);
    for(auto & x : ret) cin >> x;
    return ret;
}

constexpr int mxN = 1e5;
int n; 
ll m;
vi adj[mxN];
vl prefix[mxN], suffix[mxN];
ll subtree[mxN];
ll compliment[mxN];

void cal_subtree(int root, int parent){
    for(auto nxt : adj[root]){
        if( nxt != parent){
            cal_subtree(nxt, root);
        }
    }

    ll res = 1;
    for(int i = 0 ; i < (int)adj[root].size() ; i++){
        int kid = adj[root][i];
        if(kid == parent) {
            prefix[root][i] = res; 
            continue;
        }
        res *= 1 + subtree[kid]; 
        if(res >= m) res = res % m;
        prefix[root][i] = res;
    }
    subtree[root] = res;

    res = 1;
    for(int i = adj[root].size() - 1; i >= 0; i--){
        int kid = adj[root][i]; 
        if(kid == parent){
            suffix[root][i] = res;
            continue;
        }
        res *= 1 + subtree[kid]; 
        if(res >= m) res = res % m;
        suffix[root][i] = res;
    }
}

void cal_compliment(int root, int ind, int parent){
    if(parent >= 0){
        ll x = 1;
        if( ind - 1 >= 0) x *= prefix[parent][ind -1];
        if( ind + 1 < (int) suffix[parent].size()) x *= suffix[parent][ind+1];
        if( x >= m) x = x % m;

        ll res = x * compliment[parent];
        compliment[root] = res + 1;

        if(compliment[root] >= m){
            compliment[root] = compliment[root] % m;
        }
    }

    for(int i = 0; i < (int)adj[root].size(); i++){
        int nxt = adj[root][i];
        if(nxt != parent){
            cal_compliment(nxt, i, root);
        }
    }
}

void solve(){
    read(n);
    read(m);
    REP(i, n - 1){
        int x, y;
        read(x, y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        prefix[x].push_back(1);
        prefix[y].push_back(1);
        suffix[x].push_back(1);
        suffix[y].push_back(1);
    }
    REP(i, n){
        compliment[i] = 1;
        subtree[i] = 1;
    }
    int root = 0;
    int parent = -1;
    cal_subtree(root, parent);
   
    cal_compliment(root, 0, parent);
    REP(i, n){
        ll ans = subtree[i] * compliment[i];
        ans = ans % m;
        write(ans, "\n");
    }
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/
    int T = 1;
    for(int i = 1; i <= T; i++){
        solve();
    }
    return 0;
}

