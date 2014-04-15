'''
Coded by: Joe Ferrer
Topic: Basic Programming Class
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	The main objective of this code is to get the prime factors of
	a natural number a user inputs. If the user tries an invalid input
	i.e not a natural number, then it should catch that error by 
	notifying that it is a bad input and the user must input a natural number.
'''

from modules.user_end import get_input
from modules.math_ext import isPrime

if __name__ == "__main__":
	num = -1
	while (num<0):
		print "Enter a natural number: "
		try:
			num = int(get_input())
			if(num<0):
				print "Bad input. Input must be >= 0."
		except:
			print "Bad input. Try again."	
			
	if(isPrime(num)==1):
		if(num==1):
			print "You entered 1 w/c is a special number."
		elif(num==0):
			print "You entered 1 w/c is a special number."
		else:
			print str(num) + " is prime."
	else:
		d = 2
		factors = list()
		factorized = num
		while(isPrime(factorized)==0):
			if(factorized%d==0):
				factors.append(d)
				factorized = factorized/d
			else:
				d = d+1
				while(isPrime(d)==0):
					d = d+1
		if(isPrime(factorized)==1):
			if(factorized!=1 and factorized!=0):
				factors.append(factorized)

		print "The factors are: " + str(factors)
