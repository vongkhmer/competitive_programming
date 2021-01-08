#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n, m = list(map(int, input().split()))
    #edge[i][j] = 1 if there is an edge connecting i & j
    edge = [[0]* n for _ in range(n)]
    for _ in range(m):
        a, b = list(map(int, input().split()))
        a -= 1
        b -= 1
        edge[a][b] = edge[b][a] = 1

    #We use binary mask dp to solve this problem
    #mask in binary representation  
    mask_num = (1 << n)
    #clique is a group whose all node are directly connected by an edge
    is_clique = [False] * mask_num

    for mask in range(mask_num):
        connected = True
        for i in range(n):
            for j in range(i+1, n):
                #check if two node in the mask are connected
                if (1<<i & mask) and (1<<j & mask) :
                    if not edge[i][j]:
                        connected = False
                        break
            if not connected:
                break
        is_clique[mask] = connected

    INF = 1 << 30 
    dp = [INF] * mask_num
    dp[0] = 0

    for mask in range(1, mask_num):
        if is_clique[mask]:
            dp[mask] = 1
            continue
        submask = mask 
        #iterate over all submask
        while submask:
            dp[mask] = min(dp[mask], dp[submask] + dp[mask^submask])
            submask = (submask -1) & mask 
    
    print(dp[mask_num -1])


def main():
    solve()

if __name__ == "__main__":
    main()