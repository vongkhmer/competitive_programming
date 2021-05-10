#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    s = input()
    t = input()
    m = len(s)
    n = len(t)
    #dp[i][j] maximum LCS for s[:i+1], t[:j+1]
    dp = [ [0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):

            if s[i] == t[j]:
                dp[i][j] = 1

            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j])

            if j > 0 :
                dp[i][j] = max(dp[i][j], dp[i][j-1])

            if i > 0 and j > 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j-1] + ( 1 if s[i] == t[j] else 0))

    #backtracking
    ans = []
    i = m - 1
    j = n - 1

    while len(ans) < dp[m-1][n-1]:
        if s[i] == t[j]:
            ans.append(s[i])
            i -= 1
            j -= 1 
            continue
        ti = i
        tj = j
        while ti >= 0 and dp[ti][tj] == dp[i][j]:
            ti -= 1
        ti += 1
        while tj >= 0 and dp[ti][tj] == dp[i][j] :
            tj -=1
        tj += 1
        ans.append(s[ti])
        i = ti - 1
        j = tj - 1
    ans.reverse()
    print("".join(ans))

def main():
    solve()

if __name__ == "__main__":
    main()