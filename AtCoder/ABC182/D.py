from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = read_int_from_line()
    #range_sum[i] = a[0] + ... + a[i] : the position robot ends up after i move
    range_sum = [0] * n
    #overshoot[i] the right-most position during move a[0], ..., a[i], starting from 0
    overshoot = [0] * n
    range_sum[0] = a[0]
    overshoot[0] = max(range_sum[0], overshoot[0])
    for i in range(1, n):
        range_sum[i] = a[i] + range_sum[i-1]
        overshoot[i] = max(overshoot[i-1], range_sum[i])
        
    maxPos = 0
    curPos = 0
    #use straight forward simulation to find the maximum position
    for i in range(n):
        maxPos = max(maxPos, curPos + overshoot[i])
        curPos += range_sum[i]
        
    print(maxPos)

def main():
    solve()

if __name__ == "__main__":
    main()