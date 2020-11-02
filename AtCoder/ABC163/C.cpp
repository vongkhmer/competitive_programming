#include <stdio.h>
#include <string.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int subordinate[n];
    //automatic variables need to be initialized
    memset(subordinate, 0, n * sizeof(int)); 
    for(int i = 0 ; i < n - 1; i++){
        int boss;
        scanf("%d", &boss);
        //array's index starts with 0
        boss--;
        subordinate[boss]++;
    }
    for(int i = 0 ; i < n ; i++){
        printf("%d \n", subordinate[i]);
    }
}

int main(){
    solve();
    return 0;
}
