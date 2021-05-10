#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    #dp[i][j] : max score diff at the state a[i:j+1]
    INF = -3000e9
    dp = [ [INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        dp[i][i] = a[i]
    for i in range(n, -1, -1):
        for j in range(i, n):
            #we take right
            if j + 1 < n:
                dp[i][j+1] = max(dp[i][j+1], a[j + 1] - dp[i][j])
            #we take left
            if i - 1 >= 0:
                dp[i-1][j] = max(dp[i-1][j], a[i - 1] - dp[i][j])
                
    print(dp[0][n-1])


def main():
    solve()

if __name__ == "__main__":
    main()