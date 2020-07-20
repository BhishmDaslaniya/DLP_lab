#include <stdio.h>  
#define PI 3.1415  
#undef PI  

int main() {  
   	#ifndef PI
		printf("PI is not defined\n");  
	#endif
}