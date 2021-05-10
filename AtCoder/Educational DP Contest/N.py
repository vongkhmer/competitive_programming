#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    #prefix_sum[i] = a[0] + .. + a[i]
    prefix_sum = [0 for _ in range(n)]
    prefix_sum[0] = a[0]
    for i in range(1, n):
        prefix_sum[i] = a[i] + prefix_sum[i-1]

    #maximum possible answer
    INF = 0
    for i in range(1,n):
        INF += prefix_sum[i]
    #dp[i][j] cost for combining slimes from index i to j
    dp = [[INF for _ in range(n)] for _ in range(n)]

    for i in range(n - 1, -1, -1):
        dp[i][i] = 0
        for k in range(i + 1, n):
            for l in range(i, k):
                #s = a[i] + ... + a[k]
                s = prefix_sum[k]
                if i - 1 >= 0:
                    s -= prefix_sum[i-1]
                #first we combine slime from i to l, and l to k independently
                #and we merge it finally
                dp[i][k] = min(dp[i][k], dp[i][l] + dp[l + 1][k] + s)

    print(dp[0][n-1])

def main():
    solve()

if __name__ == "__main__":
    main()