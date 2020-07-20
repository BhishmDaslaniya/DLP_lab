#include<stdio.h>
#define a 11
int main(){	
	#if a==10
		printf("a is equal to %d  \n",a);
	#else
		printf("a is not equal to 10\n");
	#endif
}