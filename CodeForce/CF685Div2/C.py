#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def alpha_order(c):
    return ord(c) - ord('a')

def solve():
    n, k = map(int, input().split())
    #cannot use input() because it will cause TLE
    a = stdin.readline() 
    b = stdin.readline() 
    #a_alpha, b_alpha keep tracks how many time a character appears in a and b
    a_alpha = [0] * 26
    b_alpha = [0] * 26
    for i in range(n):
        a_alpha[alpha_order(a[i])] += 1 
        b_alpha[alpha_order(b[i])] += 1

    #we can only convert alphabet in increasing order
    for c in range(26):
        if a_alpha[c] < b_alpha[c]:
            #we need convert some character in a 
            #operation required to make appearance of alphabet c in a not less than in b
            required = (b_alpha[c] - a_alpha[c] + k - 1 ) // k
            for i in range(c):
                possible = min(a_alpha[i] // k , required)
                a_alpha[i] -= possible * k
                a_alpha[c] += possible * k
                required -= possible
            #if there is no enough operation to perform
            #then it is impossible to make b from a
            if required > 0 :
                print("No")
                return
            #we lock the alphabet that already matches
        a_alpha[c] -= b_alpha[c]

    print("Yes")

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
