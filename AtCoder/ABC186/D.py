#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    #since abs(a - b) = abs( b - a)
    #we can rewrite the sum in to 1 / 2 * sum[i=1..n]sum[j=1...n]( abs(ai - aj))
    #Hence it is the sum of the absolute difference of two elements ==> The order does not matter
    #Sorting the array makes the sum easy because abs(ai - aj) = ai - aj if and only i >= j
    a.sort()
    prefix_sum = [a[0]] * n
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i-1] + a[i]
    
    pair_abs_sum = 0
    for i in range(n):
        if i > 0 :
            #from j = 0..i-1, abs(ai - aj) = ai - aj
            pair_abs_sum += i * a[i] - prefix_sum[i - 1]
        #from j = (i+1)..(n-1), abs(ai - aj) = aj - ai
        pair_abs_sum += prefix_sum[n - 1] - prefix_sum[i] - (n - 1 - i) * a[i]
    
    ans = pair_abs_sum // 2
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()