#
# author: vongkh
# created: Tue Jan 19 2021
#

from sys import stdin, stdout # only need for big input

def solve():
    mxN = 100001
    #since we have to check if a number is prime or not
    #it is a good idea to check it once and save all the results
    is_prime = [True] * mxN
    is_prime[0] = False
    is_prime[1] = False
    #prime checking alogorithm
    for p in range(2, mxN):
        if is_prime[p]:
            for k in range(2, mxN):
                if p * k >= mxN:
                    break
                is_prime[p*k] = False

    #similar[i] save the number of similar number from 1..i
    similar = [0] * mxN
    similar[3] = 1
    for p in range(4, mxN):
        similar[p] = similar[p-1]
        #if p is a similar number, the total number is increased by 1
        if is_prime[p] and is_prime[ ( p + 1) // 2]:
            similar[p] += 1
    #we use the result we calculated in advance to answer the query
    q = int(input())
    for _ in range(q):
        l, r = map(int, input().split())
        ans = similar[r] - similar[l-1]
        stdout.write(str(ans))
        stdout.write("\n")
        

def main():
    solve()

if __name__ == "__main__":
    main()