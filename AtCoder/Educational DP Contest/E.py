#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    n, limit = list(map(int, input().split()))
    max_value = 1000 * n
    #dp[i] minimum weight of set of items with total cost = i
    dp = [limit + 1 for _ in range(max_value + 1)]
    dp[0] = 0

    items = [[0, 0] for _ in range(n)]

    for i in range(n):
        items[i] = list(map(int, input().split()))

    for i in range(n):
        weight, value = items[i]
        for v in range(max_value, -1, -1):
            if v - value >= 0:
                #we can try taking the item
                dp[v] = min(dp[v], dp[v - value] + weight)
            else:
                break
    
    for v in range(max_value, -1, -1):
        if dp[v] <= limit:
            print(v)
            return

def main():
    solve()

if __name__ == "__main__":
    main()