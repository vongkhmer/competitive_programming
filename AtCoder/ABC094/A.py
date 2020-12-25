#
# author: vongkh
# created: Fri Dec 25 2020
#

from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    a, b, x = read_int_from_line()
    ans = "YES"
    #it is only impossible when x is less than a or bigger than the total
    if x < a or x > a + b:
        ans = "NO"
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()