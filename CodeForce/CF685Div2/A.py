#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    if n <= 3 :
        print(n - 1)
    else:
        if n % 2 == 0:
            #one move make it to two and one susbtraction to make it 1
            print(2)
        else:
            #substract to make it even and another two move to make it 1
            print(3)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()