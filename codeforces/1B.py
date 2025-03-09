import re
def a2b(s):
	a = s.split('R')[1].split('C')
	r1,c = int(a[0]),int(a[1])
	c2 = ""

	while(c>=0):
		c = c-1
		r = c%26
		c2 = chr(ord('A')+r)+c2
		c = int(c/26)
		if(c==0):
			break
	print(c2+str(r1))

def b2a(s):
	c=""
	r=""
	for x in s:
		if(x >= '0' and x <= '9'):
			r += x
		else:
			c+=x
#	print(c,r)
	R = 'R'+r
	C = 'C'
	cc = 0 
	p = 1
	for x in c[::-1]:
		cc  += p*(ord(x)-ord('A') +1)
	#	print(p,cc)
		p *=26
	C = C+str(cc)
	print(R+C) 


	
t = int(input())
p = re.compile('R[0-9]+C[0-9]+')
for i in range(t):
	a = input()
	if(p.match(a)):
		a2b(a)
	else:
		b2a(a)
