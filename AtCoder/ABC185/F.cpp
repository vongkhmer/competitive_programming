/*
 * author: vongkh
 * created: Tue Dec 15 2020
 */

#include <iostream>
using namespace std;

constexpr int mxN = 3e5;
int segment_tree[4 * mxN];

//Belows is a simple implementation of a segment tree
//update the value at index ind to val
void update(int ind, int val, int left_bound = 0, int right_bound = mxN, int tree_ind = 1){
    if(left_bound + 1 == right_bound){
        // cout << "update tree @ " << tree_ind << " to " << val << endl;
        segment_tree[tree_ind] = val;
        return;
    }
    int mid = (left_bound + right_bound) / 2;
    if( ind < mid){
        //left tree
        update(ind, val, left_bound, mid, tree_ind * 2);
    }else{
        //update left tree
        update(ind, val, mid, right_bound, 2 * tree_ind + 1);
    }
    //update the parent tree
    segment_tree[tree_ind] = segment_tree[2 * tree_ind] ^ segment_tree[2 * tree_ind + 1];
}

//get a[qleft] ^ ...^a[qright-1]
int range_query(int qleft, int qright, int left_bound = 0, int right_bound = mxN, int tree_ind = 1){
    if(qleft >= qright) return 0;

    if(qleft == left_bound && qright == right_bound){
        return segment_tree[tree_ind];
    }
    int mid = (left_bound + right_bound) / 2;
    if(qleft >= mid){
        //query fits to the right child
        return range_query(qleft, qright, mid, right_bound, 2 * tree_ind + 1);
    }else{
        if(qright <= mid){
            //query fits to the left child
            return range_query(qleft, qright, left_bound, mid, 2 * tree_ind);
        }else{
            //need to split the tree
            int ret1 = range_query(qleft, mid, left_bound, mid, 2 * tree_ind );
            int ret2 = range_query(mid, qright, mid, right_bound, 2 * tree_ind + 1);
            return ret1 ^ ret2;
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        update(i, a);
    }
    for(int i = 0 ; i < q ; i++){
        int t, x, y;
        cin >> t >> x >> y;
        if( t == 1){
            x--;
            //first we get the original value
            int a = range_query(x, x + 1);
            //then we update the value
            update(x, a ^ y);
        }else{
            x--; y--;
            int ret = range_query(x, y + 1);
            cout << ret << "\n";
        }
    }
}

int main(){
    /*unsync iostream with stdio to improve I/O speed*/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /************************************************/
    solve();
}
