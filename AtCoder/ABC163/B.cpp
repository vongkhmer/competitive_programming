#include <iostream>
using namespace std;

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    int work_days = 0;
    for(int i = 0 ; i < m; i++){
        int assignment_requirements;
        scanf("%d", &assignment_requirements);
        work_days += assignment_requirements;
    }

    if(work_days > n){
        //he cannot finishes his assigments
        printf("-1\n");
    }else{
        int play_days = n - work_days;
        printf("%d\n", play_days);
    }
    
}

int main(){
    solve();
    return 0;
}
