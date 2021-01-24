#
# author: vongkh
# created: Tue Jan 19 2021
#

from sys import stdin, stdout # only need for big input

#round up division
def ceil_division(a, b):
    return (a + b - 1) // b
    
def solve():
    n = int(input())
    distance = [0] * n 
    start_time = [0] * n
    train_interval = [0] * n
    #read all the input
    for i in range(1, n):
        d, s , t = map(int, input().split())
        distance[i] = d
        start_time[i] = s
        train_interval[i] =t 

    #simulation
    for i in range(1, n):
        cur_time = 0
        for j in range(i, n):
            #if the train does not start yet, we wait 
            if cur_time < start_time[j]:
                cur_time = start_time[j]
            else:
                #wait until next line comes
                cur_time = ceil_division(cur_time, train_interval[j]) * train_interval[j] 
            cur_time += distance[j]
        stdout.write(str(cur_time) + "\n")
    stdout.write("0\n")

def main():
    solve()

if __name__ == "__main__":
    main()