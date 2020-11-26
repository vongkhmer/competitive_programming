#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n, q = map(int, input().split())
    s = input()
    assert n == len(s)
    #bits[i][0]/[1] keeps track the number bit 0 / 1 that appears
    #in s[0:i]
    bits = [[0,0] for _ in range(n)]
    count_1 = 0
    count_0 = 0

    for i in range(n):
        if s[i] == '0':
            count_0 += 1
        else:
            count_1 += 1
        bits[i][0] = count_0
        bits[i][1] = count_1

    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        left_most_bit = int(s[l])
        right_most_bit = int(s[r])
        #there exists such subsequence if&only if there is a bit
        #to the left that matches s[l]
        #or to the right that matches s[r]
        if l > 0:
            #check for the same bit in range 0..l-1
            if bits[l-1][left_most_bit] > 0 :
                print("YES")
                continue
        if r < n - 1:
            #check for the same bit in range r+1...n-1
            if bits[n-1][right_most_bit] - bits[r][right_most_bit] > 0:
                print("YES")
                continue
        print("NO")


def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
