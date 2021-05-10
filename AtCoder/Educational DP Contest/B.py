#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    n, k = list(map(int, input().split()))
    h = list(map(int, input().split()))
    INF = int(1e9)
    #dp[i] : minimum cost from i to n
    dp = [INF] * n 

    #cost from n-1 to n-1 is 0
    dp[n-1] = 0 

    for i in range(n-2, -1, -1):
        #we try all the step and keep the best result
        for step in range(1, min(k, n - 1 - i) + 1):
            dp[i] = min(dp[i], dp[i+step] + abs(h[i+step] - h[i]))

    print(dp[0])

def main():
    solve()

if __name__ == "__main__":
    main()