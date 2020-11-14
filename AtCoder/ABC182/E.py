from sys import stdin, stdout # only need for big input

def read_int_from_line():
    return list(map(int, input().split()))

#return index i in the sorted-array arr which arr[i] >= n
def lower_bound(arr, n):
    lb = 0
    rb = len(arr)
    if n < arr[lb]:
        return lb 
    
    while lb < rb:
        md = (lb + rb) // 2
        if arr[md] < n:
            lb = md + 1
        else:
            rb = md
    return rb

def solve():
    h,w, n, m = read_int_from_line()
    #grid[i] : 0 empty space, 1 light, -1 block
    grid = [[0] * w for _ in range(h)]
    #row[i] stores position of objects in grid[i][:]
    row = [[] for _ in range(h)]
    #col[j] stores position of objects in grid[:][j]
    col = [[] for _ in range(w)]

    #read from input the position of light
    for i in range(n):
        a, b = read_int_from_line()
        #index starts from 0
        a -= 1
        b -= 1
        grid[a][b] = 1
        row[a].append(b)
        col[b].append(a)

    #read from input the position of block
    for i in range(m):
        a, b = read_int_from_line()
        a -= 1
        b -= 1
        grid[a][b] = -1
        row[a].append(b)
        col[b].append(a)
    
    #we need array to be sorted in order to use binary search
    for i in range(h):
        row[i].sort()
    for j in range(w):
        col[j].sort()

    count_illuminated = 0

    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1:
                #it is a light
                count_illuminated += 1
            elif grid[i][j] == -1:
                #it is a block
                continue
            else:

                if len(row[i]) > 0:
                    #pos : the index of object on its right
                    pos = lower_bound(row[i], j)
                    if pos > 0:
                        #check if there is light on the left
                        left = row[i][pos-1]
                        if grid[i][left] == 1:
                            count_illuminated += 1
                            continue

                    if pos < len(row[i]):
                        #check if there is light on the right
                        right = row[i][pos]
                        if grid[i][right] == 1:
                            count_illuminated +=1
                            continue

                #do the same on col[j] to check if there is a light above or below
                if len(col[j]) > 0:
                    pos = lower_bound(col[j], i)
                    if pos > 0:
                        up = col[j][pos -1]
                        if grid[up][j] == 1:
                            count_illuminated += 1
                            continue
                    
                    if pos < len(col[j]):
                        down = col[j][pos]
                        if grid[down][j] == 1:
                            count_illuminated +=1
                            continue
    print(count_illuminated)

def main():
    solve()

if __name__ == "__main__":
    main()