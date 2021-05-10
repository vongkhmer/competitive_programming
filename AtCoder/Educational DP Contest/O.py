#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

MOD = int(1e9 + 7)

def add_mod(a, b):
    ret = a + b
    return ret if ret < MOD else ret % MOD

def solve():
    n = int(input())
    compatible = []
    for _ in range(n):
        compatible.append(list(map(int, input().split())))

    #dp[i][S] : number of way of matching men from 0 to i with subset S of women
    dp = [ [ 0 for _ in range(1<<n)] for _ in range(n)]

    #initialization for man of index 0
    for j in range(n):
        state = 1 << j
        #we can only match if they are compatible with each other
        dp[0][state] = compatible[0][j] 

    for i in range(1, n):
        for state in range(1<<n):
            if dp[i-1][state] == 0:
                continue
            
            for j in range(n):
                tmp = 1 << j
                # it should be a new state
                if tmp & state:
                    continue
                nxt_state = tmp | state
                dp[i][nxt_state] = add_mod(dp[i][nxt_state], dp[i-1][state] * compatible[i][j])
    
    print(dp[n-1][-1])

def main():
    solve()

if __name__ == "__main__":
    main()