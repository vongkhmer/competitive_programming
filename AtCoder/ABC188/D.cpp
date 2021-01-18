/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>
#include <map>

int main(){
    int n;
    int64_t c;
    scanf("%d %lld", &n , &c);

    //charge stores the change in service cost 
    // in the day of subscription/unsubscription
    std::map<int, int64_t> charge;
    for(int i = 0 ; i < n ; i++){
        int start, end;
        int64_t price;
        scanf("%d %d %lld", &start, &end, &price);
        //service cost increase at the first day
        charge[start] += price;
        //and decrease at the day after the last day
        charge[end+1] -= price;
    }
    //last_time : last_time snuke pay
    //cost : total service cost
    int last_time = 0; 
    int64_t cost = 0;
    int64_t total_cost = 0;
    for(auto [day, price] : charge){
        int period = day - last_time;
        //if the services cost more than prime subscription 
        //snuke should use prime subscription
        int64_t snuke_pay = (cost > c) ? c : cost;
        total_cost += snuke_pay * period;
        //update cost and last_time
        cost += price;
        last_time = day;
    }
    printf("%lld \n", total_cost);

}