/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <stdio.h>
#include <vector>

int n, q;
const int mxN = 2e5 + 1; 
int counter[mxN];
std::vector<int> adj[mxN];

void dfs(int node, int parent){
    if(parent >= 0){
        counter[node] += counter[parent];
    }
    for(auto next_node : adj[node]){
        if(next_node != parent){
            dfs(next_node, node);
        }
    }
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n - 1 ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0 ; i < q ; i++){
        int p, x;
        scanf("%d %d", &p, &x);
        counter[p] += x;
    }
    int root = 1;
    int parent = -1;
    //since the operation is equivalent to a single dfs update from the root
    // we only have to perform the operation once
    dfs(root, parent);
    for(int i = 1; i <= n; i++){
        printf("%d ", counter[i]);
    }
    printf("\n");
}