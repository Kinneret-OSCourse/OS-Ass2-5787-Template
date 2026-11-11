#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * Tool for finding the maximum number of processes that can be made.  If the result is 0, clean up the existing processes and try it again.
 * 
 * Author: Michael J. May
 * Version: 2026
 */

int main() {
    int max_processes = sysconf(_SC_CHILD_MAX);

    if (max_processes == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }

    printf("Maximum number of processes allowed: %d\n", max_processes);

    // Fork child processes until the system limit is reached
    int i = 0;
    for (i = 0; i < max_processes * 2; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            break;  // Exit the loop on fork failure
        } else if (pid == 0) {
            // Child process
            printf("Child process %d (pid %d) created.\n", i, getpid());
            sleep(30);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            //wait(NULL); // Wait for the child to exit
        }
    }

    printf("Created %d child processes out of %d potential processes.\n", i, max_processes);

    return 0;
}

