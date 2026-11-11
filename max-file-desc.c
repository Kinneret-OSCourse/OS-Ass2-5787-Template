#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/**
 * Tool for finding the maximum number of file descriptors.
 * 
 * Author: Michael J. May
 * Version: 2026
 */

int main() {
    int max_fd = sysconf(_SC_OPEN_MAX);
    if (max_fd == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }

    printf("Maximum number of file descriptors: %d\n", max_fd);

    // Try to open files until we reach the limit
    for (int i = 0; i < max_fd; i++) {
        int fd = open("/dev/null", O_RDONLY);
        if (fd == -1) {
            perror("open");
            printf("Opened %d files before reaching the limit.\n", i);
            break;
        }
    }

    return 0;
}

