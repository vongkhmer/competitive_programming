#
# author: vongkh
# created: Mon Apr 26 2021
#

from sys import stdin, stdout # only need for big input

def dfs(node, adj, dp):
    #we use stack instead of recursive call because python have stack limit    
    stack = []
    #the stack store state = {processing_node, start_or_finish_processing}
    stack.append([node, 1])

    while len(stack): 
        node, dfs_in = stack.pop()
        #if we just start processing, we process all the node
        if dfs_in:
            dp[node] = 0
            stack.append([node, 0])
            for next_node in adj[node]:
                #if the next_node has been processed, we don't need to process it again
                if dp[next_node] < 0:
                    stack.append([next_node, 1])
        else:
            #after we have finished processing all the next_node
            #we can update our dp result
            for next_node in adj[node]:
                dp[node] = max(dp[node], 1 + dp[next_node])


def solve():
    n, m = list(map(int, input().split()))
    #adjacent[i] contains the adjacent node
    adj = [[] for _ in range(n)]

    for _ in range(m):
        x, y = list(map(int, input().split()))
        x -= 1
        y -= 1
        adj[x].append(y)

    #dp[i] maximum lenth of path start from node i 
    dp = [-1 for _ in range(n)]

    ans = 0

    for node in range(n):
        #if we have not explor the node yet, we explore it using DFS
        if dp[node] < 0:
            dfs(node, adj, dp)
        ans = max(ans, dp[node])

    print(ans)


def main():
    solve()

if __name__ == "__main__":
    main()