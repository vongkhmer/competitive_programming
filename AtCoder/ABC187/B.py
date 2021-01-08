#
# author: vongkh
# created: Mon Jan 04 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    x = [0] * n
    y = [0] * n
    for i in range(n):
        x[i], y[i] = list(map(int, input().split()))
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            #slope = dy / dx
            #the problem ask for pair of points that abs(slope) <= 1  <==> abs(dy) <= abs(dx)
            dy = abs(y[i] - y[j])
            dx = abs(x[i] - x[j])
            if dy <= dx:
                count += 1
    print(count)

def main():
    solve()

if __name__ == "__main__":
    main()