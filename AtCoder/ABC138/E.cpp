/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    //store the positions of character appearanc in s
    // indices[0] stores index of 'a' in s, indices[1] stores index of 'b'
    vector<vector<int>> indices(26);

    for(int i = 0 ; i < s.size(); i++){
        indices[s[i] -'a'].push_back(i);
    }

    //k index of t
    // i index of s'
    int64_t k = 0, i = 0;

    for( k = 0 ; k < t.size(); k++){
        int char_index = t[k] - 'a';
        //if the character t[k] does not appear in s, we are done searching
        if(indices[char_index].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        //use binary search to find the next position of t[k]
        int64_t cur_ind = i % s.size();
        auto it = lower_bound(indices[char_index].begin(), indices[char_index].end(), cur_ind);

        if( it != indices[char_index].end()){
            //if we find it, we move to that index
            i = (i + *it - cur_ind) + 1;
        }else{
            //if not, we have to go one circle to the first appearance of t[k] in s
            i = (i + s.size() - cur_ind + indices[char_index][0]) + 1;
        }
    }

    cout << i << endl;
    return 0;
}
