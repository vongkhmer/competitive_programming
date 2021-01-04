/*
 * author: vongkh
 * created: Sat Jan 02 2021
 */


#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
constexpr int mxN = 2e5;
int n, k , l;
vector<int> road_adj[mxN], rail_adj[mxN];
int road_root[mxN], rail_root[mxN];

//set root of the connected cities by road or rail
void find_root(int node, int root, int root_arr[], vector<int> adj_arr[]){
    root_arr[node] = root;
    for(const auto & vert : adj_arr[node]){
        if(root_arr[vert] < 0) find_root(vert, root, root_arr, adj_arr);
    }
}

void solve(){
    scanf("%d %d %d", &n, &k, &l);
    //get road adjacent
    for(int i = 0 ; i < k ; i++){
        int p, q;
        scanf("%d %d", &p, &q);
        p--; q--;
        road_adj[p].push_back(q);
        road_adj[q].push_back(p);
    }
    //get railway adjacent
    for(int j = 0 ; j < l; j++){
        int r, s;
        scanf("%d %d", &r, &s);
        r--; s--;
        rail_adj[r].push_back(s);
        rail_adj[s].push_back(r);
    }
    //First reset the root to -1
    memset(road_root, -1, n * sizeof(int));
    memset(rail_root, -1, n * sizeof(int));

    for(int i = 0 ; i< n ;i++){
        //if root < 0, it does not have a group yet
        if(road_root[i] < 0) 
            find_root(i, i, road_root, road_adj);
        if(rail_root[i] < 0)
            find_root(i, i, rail_root, rail_adj);
    }
    //After DFS, two cities that are connected by roads has the same road_root
    // same for railway. Hence, if two cities are connected by bother road and railway,
    //it must have the same road_root and rail_root. 
    // => the number of cities having the same (road_root, rail_root) == the  number of connected cities
    map<pair<int,int>, int> mp;
    for(int i = 0 ; i < n ; i++){
        pair<int,int> p = {road_root[i], rail_root[i]};
        mp[p] += 1;
    }
    for(int i = 0 ; i < n ; i++){
        pair<int,int> p = {road_root[i], rail_root[i]};
        printf("%d ", mp[p]);
    }
    printf("\n");
}

int main(){
    solve();
}
