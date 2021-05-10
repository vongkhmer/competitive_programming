#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    n = int(input())
    happiness = [[0,0,0] for _ in range(n)]

    for i in range(n):
        happiness[i][:] = list(map(int, input().split()))

    #initialize dp
    dp = [[0 for j in range(3)] for i in range(n)]

    for i in range(n):
        for j in range(3):
            if i == 0:
                dp[i][j] = max(dp[i][j], happiness[i][j])
            else:
                for k in range(3):
                    #we can only selection action k if k != j
                    if j != k :
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + happiness[i][j])
    
    ans = max(dp[n-1])
    print(ans)


def main():
    solve()

if __name__ == "__main__":
    main()