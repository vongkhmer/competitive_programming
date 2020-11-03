#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y ;
    if(x > y){
        swap(x, y);
    }
    //consider the sequence after sorted
    // we want to minimize last_element
    int min_last_element = 1e9;
    int delta_val(0);

    for(int index_diff = 1 ; index_diff < n ; index_diff++){
        //index_diff is the difference of the index element x and y

        if((y - x) % index_diff == 0){
            //the condition must be satisfied for the sequence to be arithmetic sequence
            int diff = (y - x) / index_diff; 
            int smallest_element = y % diff;

            if(smallest_element == 0) {
                // smallest_element must be a positive integer
                smallest_element = diff;
            }

            int last_term = y;
            if( (last_term - smallest_element) / diff < n - 1){
                // if the sequence smallest_element, ..., x, .. , y has less than n elements
                // we need to add more elements
                last_term = smallest_element + diff * (n- 1);
            }
            //update min_last_element
            if(min_last_element > last_term){
                delta_val = diff;
                min_last_element = last_term; 
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << min_last_element << " ";
        min_last_element -= delta_val;
    }
    cout << "\n";
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
