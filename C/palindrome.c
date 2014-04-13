/*
Coded by: Joe Ferrer
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	Checks whether the input of a user is a palindrome or not
	i.e. whether the input and its reverse is equal.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void dynamic_scan(char *x) {
	char c;
	int i=1;
	while((c = fgetc(stdin)) != EOF && c != '\n') {
		x[i-1] = c;
		x = realloc(x,++i);
	}
	x[i-1] = '\0';
}

void lowercase(char *s) {
	int i;
	for(i=0;i<strlen(s);i++) {
		s[i] = tolower(s[i]);
	}
}

int main() {
	char *input;
	int i,j,r=1;
	input = (char*)malloc(2*sizeof(char));

	printf("Enter string: ");
	dynamic_scan(input);

	lowercase(input);

	i=0;
	j=strlen(input)-1;
	while(i<j) {
		if(input[i] != input[j]) {
			printf("%s is not a palindrome.\n",input);
			r=0;
			break;			
		}
		i++;
		j--;
	}
	if(r==1) 
		printf("%s is a palindrome.\n",input);
	
	free(input);
	return 0;
}