#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    n, limit = list(map(int, input().split()))

    #dp[i] maximum value we can get from limit = i
    dp = [0 for _ in range(limit + 1)]

    items = [[0, 0] for _ in range(n)]

    for i in range(n):
        items[i] = list(map(int, input().split()))

    for i in range(n):
        weight, value = items[i]
        for w in range(limit, -1, -1):
            if w - weight >= 0:
                #we can try taking the item
                dp[w] = max(dp[w], dp[w - weight] + value)
            else:
                break

    print(dp[limit])

def main():
    solve()

if __name__ == "__main__":
    main()