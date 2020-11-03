#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//convert a number to a vector of its digits
vector<int> num2Digit(long long n){
    vector<int> ret;
    while(n > 0){
        ret.push_back(n%10);
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

//calculate the sum of digits of a number
long long digit_sum(long long n){
    long long sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

//count the operation needed to change n to satisfies the requirements
long long count_operation(long long n, long long s){
    auto digits = num2Digit(n);
    //sum of digit from left
    long long sum = 0;
    //the number that might possibly satisfy the condition
    long long next_num = 0;
    for(int i = 0 ; i < (int) digits.size(); i++){
        sum += digits[i];
        if(sum > s){
            next_num += 1;
            for(int j = i ; j < (int) digits.size() ; j++){
                next_num *= 10;
            }
            break;
        }
        next_num = next_num * 10 + digits[i];
    }
    long long ret = next_num - n;
    if( digit_sum(next_num) <= s){
        return ret;
    }else{
        //we need to performs some more operations on the next number
        return ret + count_operation(next_num, s);
    }
}

void solve(){
    long long n, s;
    cin >> n >> s;
    cout << count_operation(n, s) << "\n";
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
