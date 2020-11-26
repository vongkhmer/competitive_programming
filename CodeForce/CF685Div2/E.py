#
# author: vongkh
# created: Wed Nov 25 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    n = int(input())
    mp = dict()
    a = [-1] * n
    xor_res = [0] * n
    identical_pair = []
    for i in range(1,n):
        print(f"XOR {1} {i+1}")
        xor_res[i] = int(input())
        if xor_res[i] in mp:
            identical_pair = [i, mp[xor_res[i]]]
        else:
            mp[xor_res[i]] = i 

    if 0 in mp:
        ind = mp[0]
        print(f"AND {1} {ind+1}")
        a[0] = int(input())

    elif len(identical_pair) > 0:
        ind1 = identical_pair[0]
        ind2 = identical_pair[1]
        print(f"AND {ind1 + 1} {ind2+1}")
        a[ind1] = int(input())
        a[0] = a[ind1] ^ xor_res[ind1]
    else:
        #all number are distinct and between 0 and n - 1
        #which means there is aj whose has only 1 bit different from a[0]
        
        #a[ind] whose only the last bit is different ==> a[ind] ^ a[0] == 1
        ind = mp[1]
        print(f"AND {ind+1} {1}")
        a[0] = int(input())

        #the result is not correct yet because the last bit is 0 but a[0] might be 
        #an odd number
        #we need do another query on a number whose only the second last bit is different 
        # ==> a[ind] ^ a[0] = 2
        ind = mp[2]
        print(f"AND {ind+1} {1}")
        tmp = int(input())
        #the last bit of tmp is the last bit of a[0]
        a[0] += tmp % 2

    stdout.write(f"! {a[0]} ")
    for i in range(1, n):
            a[i] = a[0] ^ xor_res[i]
            stdout.write(f"{a[i]} ")
    print(" ")

def main():
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
