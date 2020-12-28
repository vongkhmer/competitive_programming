#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

#fenwick tree that stores prefix sum
#this tree keep tracks the cell that has not been counted
mxN = 200000
tree = [0] * (mxN + 1)

def fenwick_sum(k):
    ret = 0
    while k > 0 :
        ret += tree[k]
        k -= k & (-k)
    return ret

def fenwick_increment(k, d):
    while k <= mxN :
        tree[k] += d        
        k += k & (-k)

#get a[i] + ... + a[j]
def sum(i, j):
    assert j >= i
    return  fenwick_sum(j + 1) - fenwick_sum(i)

#update a[i] to val
def update(i, val):
    before = sum(i, i)
    delta = val - before
    fenwick_increment(i + 1, delta)

def solve():
    h, w, m = list(map(int, input().split()))
    #row/col bound stores the first obstacle in each row/column
    row_bound = [w] * h 
    col_bound = [h] * w 

    for _ in range(m):
        x, y = list(map(int, input().split()))
        x -= 1
        y -= 1
        row_bound[x] = min(row_bound[x], y)
        col_bound[y] = min(col_bound[y], x)
    
    count = 0
    #first we count vertically
    for col_num, height in enumerate(col_bound) :
        if height == 0 :
            for i in range(col_num, mxN):
                update(i, 1)
            break
        count += height

    #we need this info to update whether a cell at a particular column can be counted or not
    col_info = [(col_bound[i], i) for i in range(w)]
    col_info.sort()
    ind = 0

    for row_num, width in enumerate(row_bound):
        if width == 0 :
            break
        #if the row_num is bigger than col bound, we can count cell at that column
        #Hence we need to update fenwick tree at the index
        while row_num > col_info[ind][0]:
            update(col_info[ind][1], 1)
            ind += 1
        count += sum(0, width - 1)

    print(count)

def main():
    solve()

if __name__ == "__main__":
    main()