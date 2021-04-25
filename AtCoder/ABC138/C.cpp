/*
 * author: vongkh
 * created: Wed Apr 07 2021
 */

#include <stdio.h>

int n;
const int mxN = 50;
double v[mxN];
double upper_bound = 2000;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%lf", &v[i]);
    }
    //During each operation, the total value of the element decreases by (x + y)/ 2
    //Hence, the optimal strategy is to pick the two smallest elements

    for(int i = 0; i < n - 1 ;i++){
        //find the index of the minimum element
        int index_min_element = 0;
        for(int j = 0; j < n ; j++){
            if(v[j] < upper_bound && v[j] < v[index_min_element]){
                index_min_element = j;
            }
        }
        //find the index of the second minimum element
        int index_second_min_element = index_min_element > 0 ? 0 : 1;
        for(int j = 0 ; j< n ; j++){
            if(v[j] < upper_bound && j != index_min_element && v[j] < v[index_second_min_element]){
                index_second_min_element = j;
            }
        }
        //combine those two element
        v[index_min_element] = (v[index_min_element] + v[index_second_min_element]) / 2;
        //make sure that we don't use it again
        v[index_second_min_element] = upper_bound;
    }

    for(int i = 0; i < n ; i++){
        if(v[i] < upper_bound){
            printf("%.9lf\n", v[i]);
            return 0;
        }
    }
    return 0;
}