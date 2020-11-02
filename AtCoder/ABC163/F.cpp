#include <stdio.h>
#include <vector>
using namespace std;


//DFS 1 : find number of children of each node and its immediate parent
void dfs1(int par, int node , vector<int>& parent, vector<long long>& children,vector<vector<int>>& adj){
    parent[node] = par;
    for(int i = 0 ; i < adj[node].size(); i++){
        int child_node = adj[node][i];
        if( child_node != par){
            dfs1(node, child_node, parent, children, adj);
            children[node] += children[child_node] + 1;
        }
    }
}

//DFS 2 : find the highest ancestor whose path to this node contains no node with the same color    
//or itself if no such ancestor excess
void dfs2(int par, int node, vector<int>& good_root, vector<int>& last_appearance, vector<int>& color, vector<vector<int>>& adj){
    int cur_color = color[node];
    //not actually last appearance but the next node after last_appearance
    good_root[node] = last_appearance[cur_color];
    for(const auto & kid : adj[node]){
        if(kid == par) continue;
        last_appearance[cur_color] = kid;
        dfs2(node, kid, good_root, last_appearance, color, adj);
        last_appearance[cur_color] = good_root[node];
    }
}

void solve(){
    long long n;
    scanf("%lld", &n);
    vector<int> color(n);
    vector<vector<int>> color_pos(n);
    for(int i = 0 ; i < n ; i++){
        int c;
        scanf("%d", &c);
        c--;
        color[i] = c;
        color_pos[c].push_back(i);
    }

    vector<vector<int>> adj(n);

    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 0;

    // number of children of each node
    vector<long long> children(n);
    //the highest ancestor whose path to this node contains no node with the same color
    vector<int> good_root(n, -1);
    //Immediate parent of each node
    vector<int> parent(n, -1);
    //For storing intermediate result in dfs2
    vector<int> last_appearance(n, -1);

    //Read description above @ line 6
    dfs1(-1, root, parent, children, adj); 

    //Read description above @ line 18
    dfs2(-1, root, good_root, last_appearance, color, adj);

    for(int k = 0 ; k < n ; k++){
        // if there is no such color, there is no such path
        if(color_pos[k].size() == 0){
            printf("0\n");
            continue;
        }

        //the total number of available path
        long long ans = n * (n-1) / 2 + n; 

        //cut the tree at the nodes with color k
        //i.e. we need to update children's info
        for(auto pos : color_pos[k]){
            //ancestor that we found using dfs2
            auto good_node = good_root[pos];

            if(good_node > -1){
                if(color[good_node] != k){
                    children[good_node] -= children[pos] + 1;
                }
            }else if(pos != root){
                children[root] -= children[pos] + 1;
            }
        }

        //count simple path that does not have node with color k
        for(auto pos : color_pos[k]){
            long long no_cross = 0;
            for(auto node : adj[pos]){
                if(node == parent[pos]) continue;
                if(color[node] == k) continue;
                no_cross += children[node] * (children[node] + 1) / 2 + children[node] + 1 ; 
            }
            ans -= no_cross;
        }
        //Count simple path that does not have node with color k and passes root
        if(color[root] != k){
            long long member = children[root] + 1; 
            ans -= member * (member - 1) / 2 + member;
        }

        //reconnect the nodes with color k with the rest of the tree
        for(auto pos : color_pos[k]){
            auto good_node = good_root[pos];
            if(good_node > -1){
                if(color[good_node] != k){
                    children[good_node] += children[pos] + 1;
                }
            }else if(pos != root){
                children[root] += children[pos] + 1;
            }
        }

        printf("%lld \n", ans);
    }

}

int main(){
    solve();
    return 0;
}
