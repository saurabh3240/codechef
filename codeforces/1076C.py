from math import sqrt
t = int(input())

def solve(d):
    a = (d + sqrt(d*d-4*d))/2.0;
    b = d-a
    return a,b



for x in range(t):
    d = int(input())
    if(d==1 or d==2 or d==3):
        print("N")
    elif(d==0):
        print("Y","{0:.10f}".format(0),"{0:.10f}".format(0))
    else:
        a,b = solve(d)
        if b>a:
            a,b = b,a
        print("Y","{0:.10f}".format(a),"{0:.10f}".format(b))
