#include<stdio.h>
#define a 11
int main(){	
	#if a==10
		printf("a is equal to %d  \n",a);
	#elif a > 10
		printf("a is greater than  10\n");
	#else
		printf("a is less than  10\n");	
	#endif
}