/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = {-1 , 0 , 0 , 1};
int dy[] = {0 , 1, -1, 0};

bool is_teleport(char c){
    return 'a' <= c && 'z' >= c;
}

void solve(){
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0 ; i < h ; i++){
        cin >> grid[i];
    }
    int sx, sy, gx, gy;
    vector<vector<pair<int,int>>> teleport(26);
    vector<bool> used(26, false);
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if( grid[i][j] == 'S'){
                sx = i; sy = j;
            }
            if(grid[i][j] == 'G'){
                gx = i; gy = j;
            }
            if( is_teleport(grid[i][j])){
                int ind = grid[i][j] - 'a';
                teleport[ind].push_back(make_pair(i,j));
            }
        }
    }
    //since the distance between adjacent grid and between teleport is exactly 1
    // we don't need to use Dijkstra; BFS is faster
    
    //dist[i][j] distance from start to grid[i][j], -1 if cannot be reached
    vector<vector<int>> dist(h, vector<int>(w, -1));
    //visited[i][j] == -1 means the current distance is the minimum distance
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    //que for BFS
    queue<pair<int,int>> que;
    //start with starting point sx,sy
    visited[sx][sy] = true;
    dist[sx][sy] = 0;
    que.push(make_pair(sx, sy));

    while(que.size() > 0){
        int sz = que.size();
        while(sz--){
            //the closest point in the queue that is closest to the start
            auto closest = que.front();
            que.pop(); 
            int curx = closest.first, cury = closest.second;

            for(int i = 0 ; i < 4 ; i++){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                //check if it is a valid move
                if( nx >= 0 && nx < h && ny >=0 && ny < w && grid[nx][ny] != '#'){
                    if(visited[nx][ny] == false){
                        dist[nx][ny] = dist[curx][cury] + 1;
                        visited[nx][ny] = true;
                        que.push(make_pair(nx, ny));
                    }
                }
            }
            //check if we can use teleport
            if( is_teleport(grid[curx][cury])){
                int ind = grid[curx][cury] - 'a';
                //there is no point of using teleport twice, right? You can just use once to the dist
                if( used[ind] == false){
                    for(auto tele : teleport[ind]){
                        //we don't need to update the distance of the teleport that 
                        //we already update
                        if(visited[tele.first][tele.second]) continue;
                        visited[tele.first][tele.second] = true;
                        dist[tele.first][tele.second] = dist[curx][cury] + 1;
                        que.push(tele);
                    }
                    used[ind] = true;
                }
            }
        }
        
    }
    cout << dist[gx][gy] << endl;
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
    return 0;
}
