#
# author: vongkh
# created: Fri Dec 25 2020
#

from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

def solve():
    n = int(input()) 
    x = read_int_from_line()
    y = x.copy()
    y.sort()
    #without removing any element, the middle elments are y[n/2-1] & y[n/2] 
    #removing one element does not change the order of the rest 
    #hence one of the two middle elements becomes the median
    for num in x:
        #check if the remove element is on left side or right side
        if num <= y[n//2 - 1]:
            print(y[n//2])
        else:
            print(y[n//2 - 1])
    
def main():
    solve()

if __name__ == "__main__":
    main()