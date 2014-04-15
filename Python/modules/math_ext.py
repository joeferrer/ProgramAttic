
from math import sqrt
from operator import add

def isPrime(x):
	d = 2 
	r = 1
	while(d<=sqrt(float(x))):
		if(x%d==0):
			r = 0
			break
		d = d+1
	return r

def convert(n,b):
	alphx = ['A','B','C','D','E','F']
	l = list()
	while(n>0):
		if((n%b)<10):
			l.insert(0,str(n%b))
		else:
			l.insert(0,alphx[(n%b)%10])
		n = n/b
	print "base-" +str(b) + " = " + reduce(add,l)	