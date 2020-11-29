/*
 * author: vongkh
 * created: Sun Nov 29 2020
 */

#include <iostream>
using namespace std;

bool one_move(long long a, long long b, long long c, long long d){
    if( a + b == c + d ||
        a - b == c - d ||
        abs(a -c) + abs(b -d) <= 3 ){
            return true;
        }
    return false;
}

void solve(){
    long long r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    //first case, we are already at the required position
    if( r1 == r2 && c1 == c2){
        cout << 0 << endl;
    }else{
        //second case, check if the goal is within one move
        if( one_move(r1, c1, r2, c2)){
            cout << 1 << endl;
        }else{
            //third case, we can arrive at the goal in two move
            //one to intersection of current position's diagonal and goal's diagonal
            //another one straight to the goal
            if ( (r1 + c1) % 2 == (r2 + c2) % 2){
                cout << 2 << endl;
            }else{                    
                //Fourth case, we need to change the parity of our current diagonal
                for(int dx = - 4; dx <= 4 ; dx++){
                    for(int dy = - 4; dy<=4 ; dy++){
                        int x1 = r1 + dx;
                        int y1 = c1 + dy;
                        //if after change parrity, we can make one move to the goal
                        //then the solution is 2
                        if( one_move(r1, c1, x1,y1) && one_move(x1, y1, r2, c2)){
                            cout << 2 << endl;
                            return;
                        }
                    }
                }
                //else we need 3 moves (we don't need more than 3 moves)
                cout << 3 << endl;
            }
        }
    }
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
    return 0;
}
