#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n, m, k = list(map(int, input().split()))
    is_hole = [False] * (n + 1)
    h = list(map(int, input().split()))
    for i in h:
        is_hole[i] = True
    
    #we use dp to solve this problem
    #dp[i] = dp[0] if it is a hole that send it back to 0
    #dp[i] = 1/m(dp[i+1] + .. + dp[i+m])
    #Hence, dp[i] is in form of a * dp[0] + b
    #we keep track of a and b
    a = [0] * (n + m + 1)
    b = [0] * (n + m + 1)

    # sa is a[i+1] + ... + a[i+m]
    # sb is b[i+1]  + ... + b[i+m]
    sa = 0
    sb = 0

    for i in range(n - 1, -1, -1):

        if is_hole[i]:
            a[i] = 1
            b[i] = 0
        else:
            #we use suffix sum sa and sb to update a and b
            a[i] =  sa / m
            b[i] = sb / m + 1 

        #now we update suffix sum sa and sb for next i
        sa = sa - a[i+m] + a[i] 
        sb = sb - b[i+m] + b[i]


    #to find answer, we solve dp[0] = a[0] * dp[0] + b[0] for dp[0]
    #the above equation has a solution iff a[0] != 1

    eps = 1e-8 
    if abs(a[0] - 1) < eps:
        print(-1)
    else:
        print(b[0] / ( 1 - a[0]))


def main():
    solve()

if __name__ == "__main__":
    main()