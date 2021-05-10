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

def get_path(start, path, bin_k):
    n = len(path[0])
    now = [ 0 ] * n 
    now[start] = 1
    for ind in range(len(bin_k)):
        if bin_k[ind] == 0:
            continue
        nxt = [ 0 ] * n 
        for i in range(n):
            for j in range(n):
                nxt[i] = add_mod(nxt[i], mul_mod(now[j], path[ind][j][i]))
        now = nxt
    ret = 0
    for x in now:
        ret = add_mod(ret, x)
    return ret


def solve():
    n, length = list(map(int, input().split()))
    #i use binary jump to solve this problem
    #path[k][i][j] the number path with length 2^k which starts from i and ends at j
    path = [[ [0] * n  for _ in range(n)] for _ in range(64)]

    for i in range(n):
        path[0][i][:] = list(map(int, input().split()))

    for k in range(1, 64):
        for i in range(n):
            for j in range(n):
                for l in range(n):
                    #we can go from i to l and then l to j
                    path[k][i][j] = add_mod(path[k][i][j], mul_mod(path[k-1][i][l], path[k-1][l][j]))

    #conver length to a set of binary jump
    bin_k = [0] * 64
    for b in range(64):
        if length & 1:
            bin_k[b] = 1
        length = length >> 1
    
    ans = 0

    for i in range(n):
            #get all the path
            ans = add_mod(ans, get_path(i, path, bin_k))
    
    print(ans)


def main():
    solve()

if __name__ == "__main__":
    main()