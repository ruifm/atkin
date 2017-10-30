#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void help(int h){
	switch(h){
		case 0:
			printf("\natkin: missing/wrong argument(s)\nTry 'atkin -h' for more information.\n\n");
			break;
		case 1:
			printf("\nUsage: atkin <LIMIT> [OPTION(S)]\n");
			printf("\n\t\t-p, --print \tprint all prime numbers on console (stdout)");
			printf("\n\t-w, --write <output> \tprint all prime numbers on 'output' file");
			printf("\n\t\t\t\twith no arguments, default is 'primes.txt");
			printf("\n\t\t-h, --help\tdisplay this help and exit\n\n");
			break;
	}
}

int main(int argc, char **argv){
	long int limit,n,i,j,pos,n0;
	unsigned short int *prime,control,fcontrol;
	control=0;
	fcontrol=0;
	long int sum=1;
	FILE *output;
	// tratamento do input
	switch(argc){
		case 2:
			if((!strcmp(argv[1],"-h"))||(!strcmp(argv[1],"--help"))){
				help(1);
				return 0;
			}
			break;
		case 3:
			{
			if((!strcmp(argv[2],"-p"))||(!strcmp(argv[2],"--print"))){
				control=1;
			}
			else if((!strcmp(argv[2],"-w"))||(!strcmp(argv[2],"--write"))){
				fcontrol=1;
				output=fopen("primes.txt","wt");
			}
			else {
				help(0);
				return 0;
			}
			}
			break;
		case 4:
		{
			if((!strcmp(argv[2],"-p"))||(!strcmp(argv[2],"--print"))){
				control=1;
				if((!strcmp(argv[3],"-w"))||(!strcmp(argv[3],"--write"))){
					fcontrol=1;
					output=fopen("primes.txt","wt");
				}
				else {
					help(0);
					return 0;
				}
			}
			else if((!strcmp(argv[2],"-w"))||(!strcmp(argv[2],"--write"))){
				fcontrol=1;
				output=fopen("primes.txt","wt");
				if((!strcmp(argv[3],"-p"))||(!strcmp(argv[3],"--print"))){
					control=1;
				}
				else {
					help(0);
					return 0;
				}
			}
			else {
				help(0);
				return 0;
			}
		}
		break;
		case 5:
		{
			if((!strcmp(argv[2],"-p"))||(!strcmp(argv[2],"--print"))){
				control=1;
				if((!strcmp(argv[3],"-w"))||(!strcmp(argv[3],"--write"))){
					fcontrol=1;
					output=fopen(argv[4],"wt");
				}
				else {
					help(0);
					return 0;
				}
			}
			else if((!strcmp(argv[2],"-w"))||(!strcmp(argv[2],"--write"))){
				fcontrol=1;
				output=fopen(argv[3],"wt");
				if((!strcmp(argv[4],"-p"))||(!strcmp(argv[4],"--print"))){
					control=1;
				}
				else {
					help(0);
					return 0;
				}
			}
			else {
				help(0);
				return 0;
			}
		}
		break;
		default:
			help(0);
			return 0;
	}
	if((!sscanf(argv[1],"%li",&limit))||(limit<1)||(limit%1)){
		printf("\nERROR: invalid argument for positive integer. Please try again.\n\n");
		return 0;
	}
	if(limit==1){
		printf("\nRUNTIME: 0 ms\n");
		printf("\nNumber of primes: 0\n\n");
		return 0;
	}
	if(limit==2){
		printf("\nRUNTIME: 0 ms\n");
		printf("\nNumber of primes: 0\n\n");
		return 0;
	}
	if(limit==3){
		printf("\nRUNTIME: 0 ms\n");
		printf("\nNumber of primes: 1\n\n");
		return 0;
	}

	
	//ATKIN
	limit-= 1;
	int oddlimit= floor((double)(limit+1)/2);
	int Lsqrt = ceil(sqrt((double)(limit+1)));
	int oddsqrt=ceil(sqrt((double)(limit))/2);
	if(!(prime=(unsigned short int *)malloc(oddlimit*sizeof(unsigned short int)))){
		printf("\nERROR: Number specified is too large for the amount of available.\n\n");
		return 0;
	}
	for(i=0;i<oddlimit;i++)
		prime[i]=0;
	
	prime[1]=1;
	prime[2]=1;
	
	
	clock_t t1=clock(); /*start clock */
	
	
	for(i=1;i<=Lsqrt;i++){
		for(j=1;j<=Lsqrt;j+=2){
			n=4*i*i+j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%60==1||n%60==13||n%60==17||n%60==29||n%60==37||n%60==41||n%60==49||n%60==53))
				prime[pos]= (prime[pos]? 0 : 1);
			
		}
	}
	for(i=1;i<=Lsqrt;i+=2){
		for(j=2;j<=Lsqrt;j+=2){
			n=3*i*i+j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%60==7||n%60==19||n%60==31||n%60==43))
				prime[pos]= (prime[pos]? 0 : 1);
			
		}
	}
	for(i=2;i<=Lsqrt;i++){
		for(j=i-1;j>0;j-=2){
			n=3*i*i-j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%60==11||n%60==23||n%60==47||n%60==59))
				prime[pos]=(prime[pos]? 0 : 1);
			
		}
	}
	

	/*	
	for(i=1;i<=Lsqrt;i++){
		for(j=1;j<=Lsqrt;j++){
			n=4*i*i+j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%60==1||n%60==13||n%60==17||n%60==29||n%60==37||n%60==41||n%60==49||n%60==53))
				prime[pos]= (prime[pos]? 0 : 1);
			n=3*i*i+j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%60==7||n%60==19||n%60==31||n%60==43))
				prime[pos]= (prime[pos]? 0 : 1);
			n=3*i*i-j*j;
			pos=(n-1)/2;
			if((n%2)&&(i>j)&&(pos<oddlimit)&&(n%60==11||n%60==23||n%60==47||n%60==59))
				prime[pos]= (prime[pos]? 0 : 1);
			
		}
	}
	*/
	

	/*
	for(i=1;i<=Lsqrt;i++){
		for(j=1;j<=Lsqrt;j++){
			n=4*i*i+j*j;
			pos=(n-1)/2;
			
			if((n%2)&&(pos<oddlimit)&&(n%12==1||n%12==5)){
				prime[pos]= (prime[pos]? 0 : 1);
			}
			n=3*i*i+j*j;
			pos=(n-1)/2;
			if((n%2)&&(pos<oddlimit)&&(n%12==7))
				prime[pos]= (prime[pos]? 0 : 1);
			n=3*i*i-j*j;
			pos=(n-1)/2;
			if((n%2)&&(i>j)&&(pos<oddlimit)&&(n%12==11))
				prime[pos]= (prime[pos]? 0 : 1);
			
		}
	}
	*/

	//eliminar multiplos dos quadrados
	for(i=1;i<=oddsqrt;i++){
		if(prime[i]){
			n0=(2*i+1)*(2*i+1);
			if(n0%2){
				for(n=n0;n<=limit;n+=n0){
					if(n%2){
						pos=(n-1)/2;
						prime[pos]= 0;
					}
				}
			}
		}
	}
	
	
	for(i=0;i<oddlimit;i++){
		if(prime[i])
			sum++;
	}

	
	
	
	printf("\nRUNTIME: %lf ms\n",(double)((clock()-t1)/(double)CLOCKS_PER_SEC*1000)); /*stop clock*/
	printf("\nNumber of primes:  %li\n\n",sum);
	sum=1;
	// output
	if(control||fcontrol){
		if(control)
			printf("\n2\t");
		if(fcontrol)
			fprintf(output,"\n2\t");
		j=2;
		for(i=0;i<oddlimit;i++){
			if(prime[i]){
				if(control)
					printf("%li\t",2*i+1);
				if(fcontrol)
					fprintf(output,"%li\t",2*i+1);
				if(!(sum%7)){
					if(control)
						printf("\n");
					if(fcontrol)
						fprintf(output,"\n");
				}
			if(!(j%10)) printf("\n");
			j++;
			}
		}
		printf("\n\n");
	}
	if(fcontrol)
		fclose(output);
		
	free(prime);
	return 0;
}
