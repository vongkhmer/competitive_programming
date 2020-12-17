/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(){
   int n; 
   cin >> n;
   vector<long long> a(n);
   for(int i = 0 ; i < n ; i++){
       cin >> a[i];
   }
   //sum[i] = a[0] + .. + a[i]
   vector<long long> sum(n);
   sum[0] = a[0];
   for(int i = 1 ; i < n; i++){
       sum[i] = sum[i-1] + a[i];
   }
   //minimum operation <==> maximum element remains
   //the final result is b[0] = a[0] + .. + a[i], b[1] = a[i+1] + ... + a[j], b[2] = a[j+1] + ... + a[k],...
   //with b[0] == b[1] == ... Hence we can brute force on all possible value of b[0]
   int max_remain = 1;
   for(int i = 0 ; i < n ; i++){
       //this is b[0]
       long result_element = sum[i];
       int last = i;
       int count_element = 1;
       for(int j = i ; j < n ; j++){
           long long sum_last_to_j = sum[j] - sum[last];
           if(sum_last_to_j > result_element) break;
           else if( sum_last_to_j == result_element){
               //we found the next partial sum
               last = j;
               count_element++;
           }
       }
       //if last < n -1, it means it is not possible to have b[0] == sum[i]
       if(last == n - 1){
           max_remain = max(max_remain, count_element);
       }
   }
   //since one operation reduces one element ==> num operation = n - remain
   cout << n - max_remain << "\n";
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
