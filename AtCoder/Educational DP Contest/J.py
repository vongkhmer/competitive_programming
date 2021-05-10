#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    #dp[i][j][k] expected number when there are i plate with 1, j plate with 2 , k plate with 3
    dp = [[[0 for _ in range(n + 1)] for _ in range(n + 1)] for _ in range(n + 1)]
    for k in range(n + 1):
        for j in range(n + 1):
            for i in range(n + 1):
                if i + j + k > n:
                    continue
                if i + j + k == 0:
                    continue

                s = 0
                # prob i /n for selecting plate with one sushi on
                if i > 0:
                    s += i / n * ( 1 + dp[i-1][j][k]) 
                #prob j / n for selecting plate with two sushi on
                if j > 0:
                    s += j/n * (1 + dp[i+1][j-1][k])
                #prob k / n for selecting plate with 3 shushi on
                if k > 0:
                    s += k / n * (1 + dp[i][j+1][k-1])

                #prob e for selecting empty plate and the transition is the same 
                e = (n - i - j - k) / n
                # dp[i][j][k] = s + e *(1 + dp[i][j][k])
                dp[i][j][k] = (s + e) / (1 - e)

                
    i = 0
    j = 0
    k = 0
    for plate in a:
        if plate == 1:
            i += 1
        elif plate == 2:
            j += 1
        elif plate == 3:
            k += 1

    print(dp[i][j][k])

def main():
    solve()

if __name__ == "__main__":
    main()