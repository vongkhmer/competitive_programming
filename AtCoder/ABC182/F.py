from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n, x = read_int_from_line()
    coins = read_int_from_line()
    assert n == len(coins)
    #10**18 is a fake coin, we will never use it
    coins.append(10**18)
    # coin_num convert the optimal combination coins whose amount == x 
    coin_num = [0] * n 
    #max number of each type of coin in the optimal combination (greedy works in this case)
    max_coin_num = [0] * n
    for i in range(n-1, -1, -1):
        coin_num[i] = x // coins[i]
        x = x % coins[i]
        max_coin_num[i] = coins[i+1] // coins[i] - 1
    
    #dp[i][:] consider the number of extra amount, which is less than a[i] and satisfy the condition
    #dp[i][1] the case which extra amount causes the partial combination coin_num[i:-1] to change (Let's call this coin overflow)
    #dp[i][0] the case which extra amount only change combination coin_num[0:i]
     
    dp = [[0,0] for i in range(n)]
    dp[0][0] = 1
    dp[0][1] = 0

    for i in range(1, n):
        if coin_num[i-1] == 0:
            #case 1 no coin overflow to i-1; coin_num[i-1] stays 0 and it is impossible to make overflow at this state
            dp[i][1] = 0
            dp[i][0] =  dp[i-1][0]

            #case 2 coin overflow to i-1; coin_num[i-1] becomes 1
            dp[i][0] += dp[i-1][1]
            dp[i][1] += dp[i-1][1]

        elif coin_num[i-1] == max_coin_num[i-1]:
            #case 1 no coin overflow; it stays 9
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][0]

            #case 2 coin flow; it become 0 and overflow already happened
            dp[i][1] += dp[i-1][1] 
            dp[i][0] += 0

        else:
            #overflow can always happen/not happen
            dp[i][0] = dp[i-1][0] + dp[i-1][1]
            dp[i][1] = dp[i][0]

    ans = dp[n-1][0] + dp[n-1][1]
    print(ans)


def main():
    solve()

if __name__ == "__main__":
    main()