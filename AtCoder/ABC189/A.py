#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input

    
def solve():
    c1, c2, c3 = input()
    if c1 == c2 and c2 == c3 :
        #if c1 = c2 = c3, we won
        print("Won")
    else:
        print("Lost")

def main():
    solve()

if __name__ == "__main__":
    main()