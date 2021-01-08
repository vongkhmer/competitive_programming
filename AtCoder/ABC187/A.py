#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def digit_sum(a):    
    ret = 0
    #we can use str(a) to easily convert int a to string of digit
    for digit in str(a):
        ret += int(digit)
    return ret

def solve():
    a, b = list(map(int, input().split()))
    print(max(digit_sum(a), digit_sum(b)))

def main():
    solve()

if __name__ == "__main__":
    main()