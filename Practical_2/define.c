#include<stdio.h>
#define SQRT(x) x*x
#define CUBE(x) SQRT(x)*x
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(){
	printf("Cube of 10 : %d\n",CUBE(10));
	printf("Minimum of 10 and 20 is : %d\n",MIN(10,20) );
}