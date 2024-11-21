/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Spencer Thacker
 * 
 * Brief summary of modifications:
 * Added a signal handler for SIGSEGV and the signal handler prints a message and allows the program to resume execution.
 */

#include <stdio.h>
#include <signal.h>

// Signal handler for SIGSEGV
void handle_segfault(int sig) {
    printf("SIGSEGV received! Segmentation fault occurred.\n");
}

int main (int argc, char* argv[]) {

    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}