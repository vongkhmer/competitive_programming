#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input
    
def solve():
    n = int(input())

    #we use dp to solve this problem
    #dp[i][0] : number of (x0, .., xi) that makes expression False
    #dp[i][1] : number of (x0, .., xi) that makes expression True 

    dp = [[0 for _ in range(2)] for _ in range(n + 1)]
    dp[0][0] = 1
    dp[0][1] = 1
    for i in range(1, n+1):
        s = input()
        if s == "AND" :
            #to make expression false, either we make x[i] false 
            #or x[i] true and dp[i-1] false
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) + dp[i-1][0]
            #to make expression true, we have make x[i] true and dp[i-1] true
            dp[i][1] = dp[i-1][1]
        else:
            #same way of thinking as above
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][0] + dp[i-1][1] + dp[i-1][1]

    print(dp[n][1])

def main():
    solve()

if __name__ == "__main__":
    main()