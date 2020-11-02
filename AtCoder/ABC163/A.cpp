#include <stdio.h>
#include <cmath>
using namespace std;

void solve(){
    double r;
    scanf("%lf", &r);
    //circumference = 2 * PI * R
    double circumference = 2.0 * M_PI * r; 
    printf("%.3lf\n", circumference);
}

int main(){
    solve();
}
