import sys
from functools import cache

sys.setrecursionlimit(200000)

@cache
def f(a):
    if a<=1: 
        return a;
    return f(a-1) + f(a-2)

print(f(int(input())))
