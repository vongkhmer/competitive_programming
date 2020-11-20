/*
 * author: vongkh
 * created: Fri Nov 20 2020
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <map>
using namespace std;

//we will use disjoint set union to store group
constexpr int mxN = 2e5;
int parent[mxN];
int group_size[mxN];

// find leader of the group which a belongs
int leader(int a){
    int ans = parent[a];
    while(ans != parent[ans]){
        ans = parent[ans];
    }
    return ans;
}

//check if a and b is in the same group
bool is_same(int a, int b){
    return leader(a) == leader(b);
}

//merge a's group and b's group together
int join(int a, int b){
    int leader_a = leader(a);
    int leader_b = leader(b);
    if(leader_a == leader_b){
        return leader_a;
    }
    if(group_size[leader_a] < group_size[leader_b]){
        swap(leader_a, leader_b);
    }
    parent[leader_b] = leader_a;
    group_size[leader_a] += group_size[leader_b];
    return leader_a;
}

void solve(){

    //class_info[a_group_leader] : map that store the number of group's member from each class
    map<int,map<int,int>> class_info;
    int n ,q;
    cin >> n >> q;
    //initialize group
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
        group_size[i] = 1;
    }

    for(int i = 0 ; i < n ; i++){
        int c;
        cin >> c;
        class_info[i][c] = 1;
    }
    while(q--){ 
        int query_type;
        cin >> query_type;
        if(query_type == 1){
            //merge
            int a, b;
            cin >> a >> b;
            a--; b--;
            int a_leader = leader(a);
            int b_leader = leader(b);
            if(a_leader == b_leader) continue;
            int new_leader = join(a_leader,b_leader);
            int to_merge = a_leader;
            if(new_leader == to_merge){
                to_merge = b_leader;
            }
            // we need to merge class_info too
            for(auto p : class_info[to_merge]){                        
                int key = p.first;
                int val  = p.second;
                class_info[new_leader][key] += val; 
            }
        }else{
            int x, y;
            cin >> x >> y;
            x--;
            //to get the info of a group, we need to ask the leader
            int x_leader = leader(x);
            cout << class_info[x_leader][y] << "\n"; 
        }
    }

}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();

}
