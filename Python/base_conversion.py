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

from modules.user_end import get_input
from modules.math_ext import convert


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

