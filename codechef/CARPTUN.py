
t = int(input())
for x in range(t):
	n = int(input())
	L = map(float,input().split())
	C,D,S =  map(float,input().split())
	T = D/S
	A1 = max(L)
	print("{0:.7f}".format(A1*(C-1)))
