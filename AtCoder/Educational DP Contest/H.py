#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    h, w = list(map(int, input().split()))
    grid = []
    MOD = int(1e9 + 7)
    for _ in range(h):
        grid.append(input())
    #dp[i][j] number of path from (0,0) to (i,j)
    dp = [ [0 for _ in range(w)] for _ in range(h)]
    dp[0][0] = 1
    for i in range(h):
        for j in range(w):
            #if it is an obstacle, there is no path
            if grid[i][j] == '#':
                continue
            #we can go from down (i-1, j) to (i, j)
            if i - 1 >= 0:
                dp[i][j] += dp[i-1][j]
            #we can go right from (i, j-1) to (i, j)
            if j - 1 >= 0:
                dp[i][j] += dp[i][j-1]
            #don't forget to check modular
            if dp[i][j] >= MOD :
                dp[i][j] = dp[i][j] % MOD

    print(dp[h-1][w-1])

def main():
    solve()

if __name__ == "__main__":
    main()