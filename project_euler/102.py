from __future__ import division

eps = 1e-6
def equal(a, b):
    return abs(a-b) < eps

def area(a, b, c):
    p = (a+b+c) / 2
    return (p*(p-a)*(p-b)*(p-c))**0.5

def dis(x1, y1, x2, y2):
    return ((x1-x2)**2 + (y1-y2)**2)**0.5

def area_p(x1, y1, x2, y2, x3, y3):
    a = dis(x1, y1, x2, y2)
    b = dis(x2, y2, x3, y3)
    c = dis(x3, y3, x1, y1)
    return area(a, b, c)

def func(x):
    [x1, y1, x2, y2, x3, y3] = map(int, x.strip().split(','))
    area1 = area_p(x1, y1, x2, y2, x3, y3)
    area2 = area_p(x1, y1, x2, y2, 0, 0) \
          + area_p(x2, y2, x3, y3, 0, 0) \
          + area_p(x3, y3, x1, y1, 0, 0)
    return equal(area1, area2)

with open('p102_triangles.txt', 'r') as f:
    lines = f.readlines()
ans = len(filter(func, lines))
print ans
