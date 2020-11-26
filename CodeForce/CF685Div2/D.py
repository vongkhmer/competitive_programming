#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    d, k = map(int, input().split())
    #we find game breaking point
    #observe that the player 2 can choose his point on y = x line
    #the last point of y = x line is the breaking point => player 2 wins
    #else y = x + 1 is the breaking point which player 1 can choose his strategy
    for x in range(0,d,k):
        y = x + k
        if x * x + x * x > d * d :
            break            
        if x * x + y * y > d * d:
            print("Utkarsh")
            return
    print("Ashish")

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
