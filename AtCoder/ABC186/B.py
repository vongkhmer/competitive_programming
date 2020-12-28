#
# author: vongkh
# created: Mon Dec 28 2020
#

from sys import stdin, stdout # only need for big input

def solve():
    h, w = list(map(int, input().split()))
    #All blocks can have at most height equal to the one with originally minimum height
    min_height = 100
    brick_heights = [[0] * w for _ in range(h)]
    for i in range(h):
        row = list(map(int, input().split()))
        brick_heights[i] = row
        #update minimum height
        min_height = min(min_height, min(row))

    removed_bricks = 0
    for row in brick_heights:    
        for height in row:
            #we need to make the height == min_height
            removed_bricks += height - min_height

    print(removed_bricks)

def main():
    solve()

if __name__ == "__main__":
    main()