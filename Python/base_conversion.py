'''
Coded by: Joe Ferrer
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	The main objective of this program is to convert a natural number entered by
	a user (taken as a base-10 number), to its corresponding base equivalents.
	Only bases 2->16 is considered. 
'''

import sys
from operator import add

#Function to get input from user
def get_input():
	version = sys.version_info
	if version[0] > 2:
		return input()
	else:
		return raw_input()


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

if __name__ == "__main__":
	num = -1
	while(num < 0):
		print "Enter natural number to convert: "
		try:
			num = int(get_input())
			if(num<0):
				print "Bad input. Input must be >=0."
		except:
			print "Bad input. Try again."

	if(num == 0 or num == 1):
		print str(num) + " for all bases from 2-16."
	else:	
		for i in range(2,17):
			convert(num,i)

