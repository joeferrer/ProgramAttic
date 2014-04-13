/*
Coded by: Joe Ferrer
Github: gihub.com/joeferrer
Email: joferrer16@gmail.com
Project: ProgramAttic

What this code does: 
	The main objective of this program is to convert a natural number entered by
	a user (taken as a base-10 number), to its corresponding base equivalents.
	Only bases 2->16 is considered. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BASE_MIN 2
#define BASE_MAX 16

void dynamic_scan(char *x) {
	char c;
	int i=1;
	while((c = fgetc(stdin)) != EOF && c != '\n') {
		x[i-1] = c;
		x = realloc(x,++i);
	}
	x[i-1] = '\0';
}

int isRawValid(char *y,int k) {
	int i,r=1;
	for(i=0;i<k-1;i++) {
		if(isdigit(y[i])==0) {
			r=0;
			break;
		}
	}
	return r;	
}

void convert(int n, int b) {
	char alphx[6] = {'A','B','C','D','E','F'};
	if(n==0) {
		//do nothing...
	}
	else {
		convert(n/b,b);
		if((n%b)<10) {
			printf("%d",n%b);
		}
		else{
			printf("%c",alphx[(n%b)%10]);
		}	
	}
}


void main() {
	char *raw_num;
	int base,num;

	raw_num = (char*)malloc(2*sizeof(char));
	while(isRawValid(raw_num,strlen(raw_num))==0){
		printf("Enter natural number to convert: ");
		fflush(stdin);
		dynamic_scan(raw_num);
		if(isRawValid(raw_num,strlen(raw_num))==0) {
			printf("Bad input. Try again\n.");
			free(raw_num);
			raw_num = (char*)malloc(2*sizeof(char));
		}
		else{
			num = atoi(raw_num);
		}
	}
	free(raw_num);
	if(num == 0 || num == 1) {
		printf("%d for all bases from 2-16.\n",num);
	}
	else {
		for(base=BASE_MIN;base<=BASE_MAX;base++) {
			printf("Base-%d = ",base);
			convert(num,base);
			printf("\n");
		}
	}	
}