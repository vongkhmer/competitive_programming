#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input
    
def solve():
    n, x = map(int, input().split())
    #to avoid dealing with the precision of floating point number
    #we work in the microlitter unit
    x *= 1000
    alcohol_level = 0
    for i in range(1, n + 1):
        v, p = map(int, input().split())
        #convert liquor amount to microlitter
        v *= 1000
        alcohol_level += v * p // 100
        if alcohol_level > x :
            print(i)
            return

    print(-1)

def main():
    solve()

if __name__ == "__main__":
    main()