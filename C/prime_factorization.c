/*
Coded by: Joe Ferrer
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	The main objective of this code is to get the prime factors of
	a natural number a user inputs. If the user tries an invalid input
	i.e not a natural number, then it should catch that error by 
	notifying that it is a bad input and the user must input a natural number.
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


void dynamic_scan(char *x){
	char c;
	int i=1;
	while((c = fgetc(stdin)) != EOF && c != '\n') {
		x[i-1] = c;
		x = realloc(x,++i);
	}
	x[i-1] = '\0';
}

int isNumber(char *s){
	int i=0;
	int r=1;
	while(s[i]!='\0') {
		if(isdigit(s[i])==0) {
			r = 0;
			break;
		}
		i++;
	}
	return r;
}

int isPrime(int x) {
	int result  = 1;
	int d = 2;
	while(d<=sqrt((double)x)) {
		if(x%d==0) {
			result = 0;
			break;
		}
		else{
			d++;
		}
	}	
	return result;
}

void main() {
	char *raw_input;
	int input;
	int factorized;
	int d = 2;

	//initialize raw_input
	raw_input = (char*)malloc(2*sizeof(char));

	//get raw_input from stdin
	while(isNumber(raw_input)==0) {
		printf("Enter a natural number: ");
		dynamic_scan(raw_input);
		if(isNumber(raw_input)==0) {
			printf("Bad input. Try again.\n");
			free(raw_input);
			raw_input = (char*)malloc(2*sizeof(char));
		}
	}
	//convert valid raw_input to integer type
	input = atoi(raw_input);
	free(raw_input);

	//prime factorization
	if(isPrime(input)) {
		if(input==1) 
			printf("\nYou entered 1 w/c is a special number.\n");
		else if(input==0)
			printf("\nYou entered 0 w/c is a special number.\n"); 
		else
			printf("\n%d is prime.\n",input);
	}
	else{
		printf("The factors of %d are: ",input);
		factorized = input;
		while(isPrime(factorized)==0 ) {
			//printf("\nfactorized: ",factorized);
			if(factorized%d==0) {
				printf("%d ",d);
				factorized = factorized/d;
			}
			else{
				d++;
				while(isPrime(d)==0) {
					d++;
				}
			}
		}
		if(isPrime(factorized)) {
			if(factorized != 1 && factorized != 0) 
				printf("%d\n",factorized);
		}
	}

}