#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

def gcd(a, b):
    if b == 0:
        return a
    if a < b:
        return gcd(b, a)
    return gcd(b, a % b)

def gcd_ext(a, b):
    if b == 0:
        return (1, 0)
    if a < b:
        rev_ans = gcd_ext(b, a)
        return (rev_ans[1], rev_ans[0])
    # x * b + y * (a%b) = gcd 
    # x * b + y * ( a - a//b * b) = gcd
    # y * a + (x - a//b * y) * b = gcd
    x, y = gcd_ext(b, a % b)
    return (y, x - a // b * y)

def solve():
    n, s, k = list(map(int, input().split()))
    #Takahashi will be sitting on chair ( s + k * i) % n (for i =0 , 1, ...,)
    #Hence, the question is asking whether there is  i which statisfies (s + k * i) % n == 0
    #or k * i == -s (mod n)
    if s % gcd(n, k) > 0:
        # s should divides gcd(n, k) too, because we can rewrite s = n * j - k * i 
        print(-1)
        return

    g = gcd(n, k)
    s = s // g 
    k = k // g 
    n = n // g 
    #now gcd(n, k) == 1, hence, there exist a number x which k * x == 1(mod n). Hence i == -s*x (mod n)
    #This number x can be found using exteneded gcd_ext(k, n), x * k + y * n == 1 ==> x* k = 1 (mod n)
    x, _ = gcd_ext(k, n)
    ans = -s * x
    #answer is the smallest positive element which equals -s * x(mod n)
    ans = ( n + (ans % n) ) % n
    print(ans)
    

def main():
    T = 1
    T = int(input())
    for _ in range(T):
        solve()

if __name__ == "__main__":
    main()