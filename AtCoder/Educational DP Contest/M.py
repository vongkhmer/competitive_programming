#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


MOD = int(1e9 + 7)
def mod_add(a, b):
    ret = a + b
    if ret >= MOD:
        ret = ret % MOD
    return ret

def mod_substract(a, b):
    b = (MOD - b % MOD) % MOD
    return mod_add(a, b)

def solve():
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    #dp[i][j] number of ways to distribute j candices amoung 0..j infants
    dp = [ [0 for _ in range(k+1)] for i in range(n)]

    #case 0 : trivial
    for x in range(a[0] + 1):
        dp[0][x] = 1
    
    for i in range(1, n):
        for j in range(k+1):
            #if there is no candy, there is only one way to distribute
            if j == 0:
                dp[i][j] = 1
                continue
            #dp[i][j] = dp[i][j-1] + dp[i-1][j]
            if j <= a[i]:
                dp[i][j] = mod_add(dp[i][j-1], dp[i-1][j] )
            #dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i]]
            else:
                dp[i][j] = mod_substract(mod_add(dp[i][j-1], dp[i-1][j]) , dp[i-1][j-1 - a[i]])

    print(dp[n-1][k])

def main():
    solve()

if __name__ == "__main__":
    main()