#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    n = int(input())
    p = list(map(float, input().split()))
    #dp[i][j] : probability of get j head for i coin
    dp =[ [0 for _ in range(n + 1)] for _ in range(n)]
    dp[0][0] = 1- p[0]
    dp[0][1] = p[0] 
    for i in range(0, n - 1):
        for j in range(0, i + 2):
            #have the same j heads with prob 1 - p[i+1]
            dp[i+1][j] += dp[i][j] * ( 1  - p[i+1])
            #get another head with prob p[i+1] 
            dp[i+1][j+1] += dp[i][j] * p[i+1]

    ans = 0
    for j in range(n + 1):
        #we want heads more than tails
        if j > n - j:
            ans += dp[n-1][j]
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()