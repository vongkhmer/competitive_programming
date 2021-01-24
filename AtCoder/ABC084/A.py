#
# author: vongkh
# created: Tue Jan 19 2021
#

from sys import stdin, stdout # only need for big input
    
def solve():
    m = int(input())
    #there are 48 hours from the beginning of 30th to the end of 31th
    print(48 - m)

def main():
    solve()

if __name__ == "__main__":
    main()