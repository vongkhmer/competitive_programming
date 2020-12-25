#
# author: vongkh
# created: Fri Dec 25 2020
#

from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n = int(input()) 
    a = read_int_from_line()
    a.sort()
    #observation: suppose than nCr(n1, r1]) is the solution.
    #if there is n2 in a, such that n2 > n1 ==> nCr(n2, r1) > nCr(n1, r1)
    #Hence, greedy works. We choose the biggest element for n1
    ans1 = a[n-1]

    #next we find the r1 that maximize nCr(n1, r1)
    ans2 = a[0]
    for i in range(n):
        #for monotoncity of the binomial coefficient, we consider only nCr(n, r) when r < n/2 
        b = a[i]
        if b > ans1 // 2:
            b = ans1 - a[i]
        if b > ans2:
            ans2 = a[i] 

    print(ans1, ans2)

def main():
    solve()

if __name__ == "__main__":
    main()