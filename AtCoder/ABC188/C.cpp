/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>
#include <vector>

using namespace std;

struct Player{
    int rate;
    int label;
};

Player get_winner(Player a, Player b){
    //player with higher rate win the match
    if(a.rate > b.rate) return a;
    return b;
}

int main(){
    int n;
    scanf("%d", &n);
    int num_player = 1;
    for(int i = 0 ; i < n ; i++) num_player *= 2;
    vector<Player> players(num_player);
    for(int i = 0 ; i < num_player ; i++){
        players[i].label = i + 1;
        scanf("%d", &players[i].rate);
    }

    //simulate the match
    while(num_player > 2){
        for(int i = 0 ; i < num_player ; i+= 2){
            Player winner = get_winner(players[i], players[i+1]);
            //save the result to i/2 for next round
            players[i/2] = winner;
        }
        num_player /= 2;
    }
    if(players[0].rate < players[1].rate){
        printf("%d\n", players[0].label);
    }else{
        printf("%d\n", players[1].label);
    }
}