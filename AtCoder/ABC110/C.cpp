/*
 * author: vongkh
 * created: Sat Dec 26 2020
 */

#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int mxN = 2e5;
char s[mxN+1], t[mxN+1];
//stores the first index which i-th character appears in s & t
char s_root[26], t_root[26];
void solve(){
    scanf("%s",s);
    scanf("%s",t);
    //Observation: Every same character will be converted to the same character
    //The inverse also holds.
    //Hence, to be able to convert s to t, we need character appears in the exact the same pattern
    fill(s_root, s_root + 26, -1);
    fill(t_root, t_root + 26, -1);

    //Don't use strlen in loop because it will recalculate every time even if the string length stays the same
    int sz = strlen(s);
    for(int i = 0 ; i < sz ; i++){
        int ind_s = s[i] - 'a';
        int ind_t = t[i] - 'a';
        //if it is the first time this character appear, we set s_root & t_root
        if(s_root[ind_s] < 0) s_root[ind_s] = i;
        if(t_root[ind_t] < 0) t_root[ind_t] = i;

        //since, we are now looking at the same position i-th, we only need
        //the early appearance to be the same to have the exact same pattern
        if(s_root[ind_s] != t_root[ind_t]){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main(){
    solve();
}
