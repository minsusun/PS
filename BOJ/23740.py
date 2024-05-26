# 23740
import sys
n = int(input())
L = []
for _ in range(n):
    L.append(list(map(int,sys.stdin.readline().split())))
realL = []
L.sort(key = lambda x : x[0])
for i in range(n):
    if realL == []:
        realL.append(L[0])
    elif realL[-1][1] < L[i][0]:
        realL.append(L[i])
    else:
        realL[-1][1] = max(realL[-1][1] , L[i][1])
        realL[-1][2] = min(realL[-1][2], L[i][2])
a = len(realL)
print(a)
for i in range(a):
    print(realL[i][0],end = " ")
    print(realL[i][1],end = " ")
    print(realL[i][2])