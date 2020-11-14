from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = read_int_from_line()
    assert n == len(a)
    max_GCDness = 0
    ans = 0
    #since n and A are small, we can just do bruteforce
    for k in range(2, 1001):
        divisible_count = 0
        for num in a:
            if num % k == 0:
                divisible_count += 1
        if max_GCDness < divisible_count:
            max_GCDness = divisible_count
            ans = k
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()