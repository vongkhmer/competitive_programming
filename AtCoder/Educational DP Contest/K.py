#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input


def solve():
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    #dp[i] tells if a player if he is in the state that has number of stone == i
    dp = [0 for _ in range(k + 1)]

    for i in range(k + 1):
        for move in a:
            #he can win if he makes his opponent falls in to losing state
            if i - move >= 0 and dp[i-move] == 0:
                dp[i] = 1
                break
    if dp[k]:
        print("First")
    else:
        print("Second")

def main():
    solve()

if __name__ == "__main__":
    main()