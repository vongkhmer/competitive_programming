#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

MOD = int(1e9 + 7)

def add_mod(a, b):
    ret = a + b
    return ret if ret < MOD else ret % MOD

def dfs(node, parent, adj, dp):
    #since stack size is limit in python, we implemented it using stack
    stack = []
    stack.append((1, node, parent))

    while len(stack):
        enter, node, parent = stack.pop()
        if enter :
            stack.append((0, node, parent))
            for nxt in adj[node]:
                if nxt != parent:
                    stack.append((1, nxt, node))
        else:
            for nxt in adj[node]:
                if nxt != parent:
                    #if the node is painted white, we are free to color its childern to any color
                    dp[node][0] *= (dp[nxt][0] + dp[nxt][1]) % MOD
                    if dp[node][0] >= MOD:
                        dp[node][0] = dp[node][0] % MOD
                    #if the node is painted black, we can only color its children to white
                    dp[node][1] *= dp[nxt][0]
                    if dp[node][1] >= MOD:
                        dp[node][1] = dp[node][1] % MOD
def solve():
    n = int(input())
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = list(map(int, input().split()))
        x -= 1
        y -= 1
        adj[x].append(y)
        adj[y].append(x)
    root = 0
    #dp[i][0] number of way to color subtree[i] with node[i] white
    #dp[i][1] number of way to color subtree[i] with node[i] black
    dp = [[1, 1] for _ in range(n)]

    dfs(root, -1, adj, dp)

    ans = dp[root][0] + dp[root][1]
    if ans >= MOD:
        ans = ans % MOD
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()