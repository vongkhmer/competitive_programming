from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    #since n is big, we read input n as string
    n = input()
    num_digit = len(n)
    #state in binary representation represents how we delete/keep digits
    #i-th digit of state = 0 means we delete i-th digit of n
    state = 0
    # 111..1 is the max_state which we keeps everything
    MAX_STATE = (1 << num_digit) - 1
    ans = num_digit
    while state <= MAX_STATE :
        #remember an integer is divisible by 3 if and only if 
        #the sum of its digit is divisible by 3
        digit_sum = 0
        delete_count = 0
        for i in range(num_digit):
            #check if we keep i-th digit in this state
            if ((1 << i) & state) != 0 :
                digit_sum += int(n[i])
            else:
                #if not, it means we deleted the i-th digit
                delete_count += 1

        if digit_sum % 3 == 0 and ans > delete_count:
            ans = delete_count
        state += 1
    
    #it is not allowed to delete all digits
    if ans == num_digit:
        ans = -1
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()