from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    follower, following = read_int_from_line()
    maximum_following = 2 * follower + 100
    print(maximum_following - following)

def main():
    solve()

if __name__ == "__main__":
    main()