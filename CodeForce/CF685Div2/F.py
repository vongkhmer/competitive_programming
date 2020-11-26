#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n, m = list(map(int, input().split()))
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))
    
    #the point is to find a win condition for yourself and
    #force your oponent to be in the lose condition
    #the win condition is this problem is a simple implementation 
    #but the proof is math heavy. Please check the official editorial
    win = False 
    for diagonal in range(n + m - 1):
        xor = 0
        for i in range(diagonal + 1):
            j = diagonal - i
            if j >= m or i >= n:
                continue
            xor = xor ^ a[i][j]
        if xor != 0:
            win = True
    if win :
        print("Ashish")
    else:
        print("Jeel")

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
