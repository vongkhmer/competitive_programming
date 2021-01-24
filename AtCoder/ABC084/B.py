#
# author: vongkh
# created: Tue Jan 19 2021
#

from sys import stdin, stdout # only need for big input
    
def solve():
    a, b = map(int, input().split())
    postal_code = input().split("-")
    #check if the postal code satisfies the condition
    if len(postal_code) == 2 \
      and len(postal_code[0]) == a \
      and len(postal_code[1]) == b: 

        print("Yes")
        return

    print("No")


def main():
    solve()

if __name__ == "__main__":
    main()