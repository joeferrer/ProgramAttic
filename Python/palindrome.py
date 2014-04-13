'''
Coded by: Joe Ferrer
Topic: Basic Programming Class
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	Checks whether the input of a user is a palindrome or not
	i.e. whether the input and its reverse is equal.
'''
import sys

#Function to get input from user
def get_input():
	version = sys.version_info
	if version[0] > 2:
		return input()
	else:
		return raw_input()


if __name__ == "__main__":
	
	print "Type your string: "
	string = get_input()
	i = 0 
	j = len(string)-1
	r = 1
	string = string.lower()
	while(i<j):
		if(string[i] != string[j]):
			print string + " is not a palindrome."
			r=0
			break
		i = i+1
		j = j-1
	if(r==1):
		print string + " is a palindrome."