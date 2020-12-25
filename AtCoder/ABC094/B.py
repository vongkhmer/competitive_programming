#
# author: vongkh
# created: Fri Dec 25 2020
#

from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n, m , x = read_int_from_line()
    costs = [0] * (n+1)
    a = read_int_from_line()
    for square in a:
        costs[square] = 1
    
    #we calculate the cost from x to zero and to n
    cost_to_zero = 0
    cost_to_n = 0

    #going to zero costs the same as going from zero
    #because there is no troll gate at 0
    for i in range(x):
        cost_to_zero += costs[i]
    
    #we will pay at troll gates between [x+1, n]
    for i in range(x+1,n):
        cost_to_n += costs[i]

    #we choose the path with the lowest cost
    ans = min(cost_to_zero, cost_to_n)
    print(ans)
    
def main():
    solve()

if __name__ == "__main__":
    main()