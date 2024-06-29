import sys
input=sys.stdin.readline

n=int(input())
a=[]
sum=0
cnt=0
for i in range(n):
    b=int(input())
    a.append(b)
max=a[n-1]
for j in range(n-1,-1,-1):
    if a[j]>max:
        max=a[j]
        cnt+=1
print(cnt+1)
