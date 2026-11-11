#include <stdio.h>
#include <stdlib.h>

/**
 * Second part of starter code for function address and memory region exploration.
 * 
 * Author: Michael J. May
 * Version: 2025
 */

extern double stuff;

/* A recursive function */
int recur(int i, float j, char k) {
	/* A stack allocated variable within a recursive function */
	int localInt = i;
	float localFloat = j;
	char localChar = k;
	double localArr[1024];
	
	void *return_addr = __builtin_return_address(0);
    printf("=== recur() call %d - Return address: %p ===\n", i, return_addr);

	/* TODO 1: Fix the following calls to print the addresses of the parameters */
	printf("recursive call %d: parameter int %d @ %p\n", i, i, i);	
	printf("recursive call %d: parameter float %2.2f @ %p\n", i, j, j);	
	printf("recursive call %d: parameter char %c @ %p\n", i, k, k);	

	/* TODO 2: Fix the following calls to print the addresses of the local variables */
	printf("recursive call %d: stack int %i @ %p\n", i, localInt, localInt);
	printf("recursive call %d: stack float %2.2f @ %p\n", i, localFloat, localFloat);
	printf("recursive call %d: stack char %c @ %p\n", i, localChar, localChar);	
	printf("recursive call %d: stack double[] %2.2f @ %p\n", i, localArr[0], localArr);		
	
	/* TODO 3: Fix the following call to print the addresses of the static variable */	
	printf("static data: stuff %2.2f @ %p\n\n", stuff, stuff);
	
    if (i > 0) {
        return recur(i - 1, j - 1.5, k + 1);
    }

    return 0;
}

