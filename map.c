#include <stdio.h>
#include <stdlib.h>

/**
 * Starter code for function address and memory region exploration.
 * 
 * Author: Michael J. May
 * Version: 2025
 */

/* A recursive function */
int recur(int i, float j, char k); 

/* Statically allocated variable */
int foo;
/* Statically allocated, pre-initialized variables */
double stuff = 7;
float bar = 4.5;

int main(int argc, char *argv[]) {
    
	void *return_addr = __builtin_return_address(0);
    printf("=== main() entry - Return address: %p ===\n\n", return_addr);
	
	/* A stack allocated variable */
    int i;

    /* Dynamically allocate some stuff */
    char *buf1 = malloc(190);
    /* ... and some more stuff */
    char *buf2 = malloc(190);

    printf("_main @ %p\n", &main);
    printf("recur @ %p\n", &recur);

    /* TODO 1: Fix to get the address of the stack variable */
    printf("_main stack: %p\n", i);

    /* TODO 2: Fix and expand to get the address of the static variables (stuff, foo, bar) */
	printf("static data: stuff %p\n", stuff);
	printf("static data: bar   %p\n", bar);
    printf("static data: foo   %p\n", foo);
	
    printf("Heap: malloc 1: %p\n", buf1);
    printf("Heap: malloc 2: %p\n", buf2);
    recur(2, bar, 'a');
	
    return 0;
}
