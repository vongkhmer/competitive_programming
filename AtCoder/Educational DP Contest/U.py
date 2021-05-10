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
    n = int(input())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

    #dp[s] : maximum score when arrang set s of student
    dp = [ 0 for _ in range(1<<n)]

    score = [0 for _ in range(1<<n)]

    for m in range(1<<n):
        for i in range(n):
            if (m >> i) & 1 == 0 :
                continue
            for j in range(i, n):
                if (m >> j) & 1 == 0:
                    continue
                score[m] += a[i][j]

    for m in range(1<<n):
        s = m
        #we can group all of them
        dp[m] = score[m]
        while s > 0:
            #or we can make one group s first
            #then think the rest later (m - s)
            dp[m] = max(dp[m], score[s] + dp[m-s])
            s = (s-1) & m

    print(dp[-1])


def main():
    solve()

if __name__ == "__main__":
    main()