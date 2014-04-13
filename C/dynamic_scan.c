/*
Coded by: Joe Ferrer
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	The main objective of this code is to scan a user's input
	as a string by dynamically allocating space for that input 
	and not predefining a character string i.e. not doing this:
		char string[<predefined_no.>]
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char c;
	char *input;
	int i;
	input = (char*)malloc(2*sizeof(char));
	printf("Enter string: ");
	i=1;
	while((c = fgetc(stdin)) != EOF && c != '\n') {
		printf("c = %c\n",c);
		input[i-1] = c;
		input = realloc(input,++i);
	}	
	input[i-1] = '\0';
	printf("input = %s\n",input);
	free(input);
	return 0;
}