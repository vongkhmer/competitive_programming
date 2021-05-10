#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

MOD = int(1e9 + 7)

def add_mod(a, b):
    return (a + b) % MOD
def mul_mod(a,b):
    return (a * b) % MOD

def solve():
    k = input() 
    k = [ int(c) for c in k]
    k.reverse()
    d = int(input())

    #dp[i][j][0]: number of numbers that is less then k[0:i] which has its digit sum equals to j(mod D)
    #dp[i][j][1]: number of numbers that is with i-digits which has its digit sum equals to j(mod D)
    dp = [ [[0,0] for _ in range(d)] for _ in range(len(k))]

    for dg in range(10):
        res = dg % d
        dp[0][res][1] += 1

    for dg in range(k[0] + 1):
        res = dg % d
        dp[0][res][0] += 1

    for i in range(len(k) - 1):
        for rem in range(d):
            for dg in range(10):
                res = (rem + dg) % d
                dp[i+1][res][1] = add_mod(dp[i][rem][1], dp[i+1][res][1]) 
    
    for i in range(len(k) - 1):
        for rem in range(d):
            for dg in range(k[i+1]):
                res = (rem + dg) % d
                dp[i+1][res][0] = add_mod(dp[i][rem][1], dp[i+1][res][0])  
            # for k[i]
            res = (rem + k[i+1]) % d
            dp[i+1][res][0] = add_mod(dp[i][rem][0], dp[i+1][res][0])

    #in this dp, we also count 0 in
    #so we need to substract 1
    ans = dp[len(k) - 1][0][0] - 1 + MOD
    
    ans = ans % MOD

    print(ans)



def main():
    solve()

if __name__ == "__main__":
    main()