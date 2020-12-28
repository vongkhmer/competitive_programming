#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

def is_good(n):
    #check if it contains 7 in decimal representatin
    m = n
    while m > 0 :
        if m % 10 == 7:
            return False
        m =  m // 10
    #check if it contains 7 in octal representation
    m = n 
    while m > 0:
        if m % 8 == 7:
            return False
        m = m // 8
    return True

def solve():
    n = int(input())
    count = 0
    #since n is small, we can just do the brute force
    for num in range(1, n + 1):
        if is_good(num):
            count += 1
    print(count)

def main():
    solve()

if __name__ == "__main__":
    main()