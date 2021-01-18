/*
 * author: vongkh
 * created: Sun Jan 17 2021
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

struct City{
    int64_t gold_price;
    int index; //city number
};

int n, m;
constexpr int mxN = 2e5;
constexpr int64_t max_import_price = 3e9; 
std::vector<int> edges[mxN];
City cities[mxN];
//gold_prices[i] : price of gold in city i
int64_t gold_prices[mxN];
//cheapest price of gold that can be import to a cities
int64_t cheapest_import_prices[mxN];
//answer : maximum profit
int64_t ans = -max_import_price;

bool cmp_city(const City& a, const City& b){
    if(a.gold_price == b.gold_price) return a.index < b.index;
    return a.gold_price < b.gold_price;
}

void dfs(int ind, int64_t cheapest){
    //update import price for current city
    cheapest_import_prices[ind] = cheapest;
    //update ans
    ans = std::max(ans, gold_prices[ind] - cheapest);
    //update import price for next city
    cheapest = std::min(cheapest, gold_prices[ind]);

    for(const auto& c : edges[ind]){
        //only do recursive if the import price can be updated
        if(cheapest_import_prices[c] > cheapest){
            dfs(c, cheapest);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++){
        int64_t gold_price;
        scanf("%lld", &gold_price);
        cities[i] = {gold_price, i};
        cheapest_import_prices[i] = max_import_price;
        gold_prices[i] = gold_price;
    }
    for(int i = 0 ; i < m ; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        from--; to--;
        edges[from].push_back(to);
    }
    // we need to sort the cities,
    // so that we don't have to update import price more than once for each city
    std::sort(cities, cities + n, cmp_city);
    for(int i = 0 ; i < n ; i++){
        int ind = cities[i].index;
        if(cheapest_import_prices[ind] < max_import_price) continue;
        dfs(ind, max_import_price);
    }
    printf("%lld\n", ans);
}