#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n, w = list(map(int, input().split()))
    ans = n // w 
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()