/*
 * author: vongkh
 * created: Thu Dec 17 2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment 
{
    //x1 : left end, x2 : right end, x1 <= x2
    int x1, x2;
};


void solve(){
    int n;
    cin >> n;
    vector<Segment> segments(n);
    //left : stores the left end, right : stores the right end
    vector<int> left(n), right(n);
    for(int i = 0 ; i < n ; i++){
        int x1, x2;
        cin >> x1 >> x2;
        left[i] = x1;
        right[i] = x2;
        segments[i] = {x1, x2};
    }
    //we need to sort it to use binary search
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    // minimum segment remove <==> maximum segment remains
    int max_intersection = 1; 
    for(const auto & seg : segments){
        //we count how many segment remove if we let seg as the segment in the problem description
        //it is easier to find segment that does not intersection
        // case 1: segment is to the left of seg ==> segment.right < seg.x1
        auto it1 = lower_bound(right.begin(), right.end(), seg.x1);
        int no_intersection_left = distance(right.begin(), it1);
        // case 2: segment is to the right of seg ==> segment.left > seg.x2
        auto  it2 = lower_bound(left.begin(), left.end(), seg.x2 + 1);
        int no_intersection_right = distance(it2, left.end());
        //the remained segments are the segment that intersects
        int num_intersection = n - no_intersection_left - no_intersection_right;
        max_intersection = max(max_intersection, num_intersection);
    }
    //The problem asks us to output the number of remove
    cout << n - max_intersection << "\n";
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
