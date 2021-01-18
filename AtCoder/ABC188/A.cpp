/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>
#include <cstdlib>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    int point_diff = std::abs(x - y);
    //loser can win with 3 points goal iff the point difference is less than 3
    if(point_diff < 3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}