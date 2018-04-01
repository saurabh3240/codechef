n,d =raw_input().split()
n = int(n)
d = int(d)
arr=[]
x=n
while x >0:
    z = int(input())
    arr.append(z)
    x-=1
arr.sort()
ans =0
i=0
while i<n-1:
    if(arr[i+1]-arr[i]<=d):
        ans+=1
        i+=2
    else:
        i+=1

print ans
