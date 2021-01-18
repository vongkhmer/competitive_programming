/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>
#include <cstdlib>
#include <map>

int64_t x, y;
std::map<int64_t, int64_t> memo;

int64_t get_operation_num(int64_t z){
    //get the number of operation need to transform z back to x
    //each stop we have three choices : increment, decrement, divide by 2
    //Observation: divide by 2 and +/- later is more efficient 
    if(memo.find(z) != memo.end()) return memo[z]; 
    if(z == 1) return std::abs(z - x);
    int64_t ans = std::abs(z - x);
    if(z%2){
        //if z is odd we can only do +/-
        ans = std::min(ans, get_operation_num(z-1)+1);
        ans = std::min(ans, get_operation_num(z+1) + 1);
    }else{
        //if z is even, it is optimal to try to /2
        ans = std::min(ans, get_operation_num(z/2) + 1);
    }
    return memo[z] = ans;
}

int main(){
    scanf("%lld %lld", &x, &y);
    //we solve this problem by thinking inversely
    //how to get x from y
    int64_t ans = get_operation_num(y);
    printf("%lld \n", ans);
    return 0;
}