/*
 * author: vongkh
 * created: Sat Jan 02 2021
 */


#include <stdio.h>
#include <cstring>
using namespace std;

//char array that contains all the vowel
constexpr int mxN = 1e5;
char s[mxN+1];
const char* target[] = {"dream", "erase", "er", "r"};

int word_type(int ind){
    //return type of word start at index ind
    // -1 : invalid word
    //ret = 0-3 : word == target[ret]
    if(s[ind] == 'd'){
        for(int i = 0 ; i < 5; i++){
            if(s[ind+i] != target[0][i]) return -1;
        }
        return 0;
    }else if(s[ind] == 'e'){
        for(int i = 0 ; i < 5 ; i++){
            if(s[ind+i] != target[1][i]){
                if(i > 1) return 2;
                else return -1;
            }
        }
        return 1;
    }else if(s[ind] == 'r'){
        return 3;
    }else{
        return -1;
    }
}

void solve(){
    scanf("%s",s);
    int n = strlen(s);
    int ind = 0;
    //the valid string are th combination of (base) & (base + suffix)
    //and since (suffix)(x)  != base(y) ==> (base + suffix)(x) != (base)(base)(y), 
    //if we remove base first, we will not confuse suffix "-er" with base "erase"

    int last_wt = -1;
    while(ind < n){
        int wt = word_type(ind);
        if(wt < 0){
            //there is no invalid word, hence the algorithm ends here
            printf("NO\n");
            return;
        }else if(wt < 2){
            //the current word is the base word, we processed it without thinking
            ind += 5; 
            last_wt = wt;
        }else if( wt - last_wt == 2){
            //now the current word is a suffix, we need to check if it is the correct suffix of 
            //the last word
            ind += (wt == 2 ? 2:1);
            last_wt = wt;
        }else{
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    return;
}

int main(){
    solve();
}
