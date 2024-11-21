/*
Demonstration Commands
kill -SIGUSR1 <pid>
*/
/**
 * File: signal_sigaction.c
 * Modified by: Spencer Thacker <thackers@msoe.edu>
 * 
 * Brief summary of program:
 * Registering a signal handler using sigaction
 * Handling SIGUSR1 and retrieving sender information
 * Observing detailed signal information using siginfo_t
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler function
void handle_signal(int sig, siginfo_t *siginfo, void *context) {
    printf("Received signal: %d from process: %d\n", sig, siginfo->si_pid);
}

int main() {
    struct sigaction sa;

    // Clear the sigaction structure
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Use SA_SIGINFO to enable additional information
    sa.sa_sigaction = handle_signal; // Set the handler function

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        printf("An error has occurred!\n");
        exit(1);
    }

    printf("Waiting for SIGUSR1... (PID: %d)\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}

