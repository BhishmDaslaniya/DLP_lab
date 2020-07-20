#include<stdio.h>
#define sq(x) x*x
#define cube(x) sq(x)*x

int main(){
	int x = 10;
	printf("%d",cube(x));
	return 0;
}