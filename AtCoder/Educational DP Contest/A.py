#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    n = int(input())
    h = list(map(int, input().split()))
    #dp[i] : minimum cost from i to n
    dp = [0] * n 

    #cost from n - 2  to n - 1 is abs(h[n-2] - h[n-1]); we dont have other choice
    dp[n-2] = abs(h[n-2] - h[n-1])

    for i in range(n-3, -1, -1):
        #first choice: we jump to i+1
        dp[i] = dp[i+1] + abs(h[i+1] - h[i])
        #second choice: we jump to i + 2
        dp[i] = min(dp[i], abs(h[i+2] - h[i]) + dp[i+2]) 

    print(dp[0])


def main():
    solve()

if __name__ == "__main__":
    main()