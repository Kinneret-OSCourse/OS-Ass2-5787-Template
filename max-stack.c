#include <stdio.h>

/**
 * Tool for finding the maximum size for the program's stack.
 * 
 * Author: Michael J. May
 * Version: 2025
 */

// Static variable to track the total stack size used
static long total_stack_size = 0;

void recursive_function(int depth) {
    char stack_variable[1024];  // A small buffer to minimize memory usage

    // Accumulate the stack size used in this call
    total_stack_size += sizeof(stack_variable);

    printf("Current stack depth: %d with size %ld\n", depth, total_stack_size);

    // Recursively call the function until a stack overflow occurs
    recursive_function(depth + 1);
}

int main() {
    int depth = 0;
    printf("Testing stack size limit...\n");

    // Start the recursion
    recursive_function(depth);

    printf("Reached maximum stack depth without a stack overflow.\n");
    printf("Total stack size used: %ld bytes\n", total_stack_size);
    return 0;
}

