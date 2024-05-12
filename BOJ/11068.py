import sys
input=sys.stdin.readline
n=int(input())
for i in range(n):
    num=int(input())
    flag=False
    for j in range(2,65):
        c=num
        num_c=list()
        while c!=0:
            num_c.insert(0,c%j)
            c=c//j
        if num_c==num_c[::-1]:
            flag=True
            break
    print(int(flag))
