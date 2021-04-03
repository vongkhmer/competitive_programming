#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input
    
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    #we simulate all possible (l, r) pair
    #Note that, the optimal value x is the minimum of element between l and r
    ans = 0
    for i in range(0, n):
        #initialize x to a[i]
        x = a[i]
        for j in range(i, n): 
            #if a[j] is the minimum element, we update x to a[j]
            if a[j] < x :
                x = a[j] 

            #check if we could improve the answer
            if x * (j - i + 1) > ans :
                ans = x * ( j - i + 1)
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()