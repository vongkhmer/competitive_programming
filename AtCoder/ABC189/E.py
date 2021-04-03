#
# author: vongkh
# created: Wed Mar 31 2021
#

from sys import stdin, stdout # only need for big input

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def print(self):
        print(self.x, self.y)

class Mat:
    def __init__(self):
        self.row1 = [1,0,0]
        self.row2 = [0,1,0]

    #use transform matrix to perform affine transform on a point
    def transform_point(self, p):
        a, b, c = self.row1
        x = p.x * a + p.y * b + c 
        a, b, c = self.row2
        y = p.x * a + p.y * b + c 
        return Point(x,y)

    #rotate 90 clockwise 
    def rotate_90(self):
        # x' = y, y' = -x
        ret = Mat()
        ret.row1 = self.row2.copy()
        ret.row2 = self.row1.copy()
        for i in range(3):
            ret.row2[i] *= -1
        return ret 

    #rotate 90 counter clockwise
    def rotate_90_counter(self):
        # x' = -y, y' = x
        ret = Mat()
        ret.row1 = self.row2.copy()
        ret.row2 = self.row1.copy()
        for i in range(3):
            ret.row1[i] *= -1
        return ret

    def flip_x(self, p):
        # x' = 2 * p - x, y' = y
        ret = Mat()
        ret.row2 = self.row2.copy()
        ret.row1 = self.row1.copy()
        for i in range(3):
            ret.row1[i] *= -1
        ret.row1[2] += 2 * p
        return ret
    
    def flip_y(self, p):
        # x' = x, y' = 2 * p - y
        ret = Mat()
        ret.row2 = self.row2.copy()
        ret.row1 = self.row1.copy()
        for i in range(3):
            ret.row2[i] *= -1
        ret.row2[2] += 2 * p
        return ret
    
    
def solve():
    n = int(input())
    points = [Point(0,0) for _ in range(n)]

    for i in range(n):
        x, y = list(map(int, input().split()))
        points[i].x = x
        points[i].y = y

    m = int(input())

    #since all the transforms are affine transform,
    #we just need to stores the resulted transform matrix
    transform_mat = [Mat() for _ in range(m+1)]
    for i in range(1, m+1): 
        op = list(map(int, input().split())) 
        if op[0] == 1:
            transform_mat[i] = transform_mat[i-1].rotate_90()
        elif op[0] == 2:
            transform_mat[i] = transform_mat[i-1].rotate_90_counter()
        elif op[0] == 3:
            p = op[1]
            transform_mat[i] = transform_mat[i-1].flip_x(p)
        elif op[0] == 4:
            p = op[1]
            transform_mat[i] = transform_mat[i-1].flip_y(p)
        else:
            assert False
    
    q = int(input())
    for _ in range(q):
        a, b = list(map(int, input().split()))
        b -= 1
        ret = transform_mat[a].transform_point(points[b])
        ret.print()
            

def main():
    solve()

if __name__ == "__main__":
    main()