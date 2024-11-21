/**
 * File: recv_signal.c
 * Modified by: Spencer Thacker <thackers@msoe.edu>
 * 
 * Brief summary of program:
 * Sends SIGUSR1 signal with additional data using sigqueue.
 * ./send_signal <pid>
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_signal(int sig, siginfo_t *siginfo, void *context) {
    printf("Received signal: %d\n", sig);
    printf("Received value: %d\n", siginfo->si_value.sival_int);
    printf("Signal sent by process: %d\n", siginfo->si_pid);
}

int main() {
    struct sigaction sa;

    // Clear the sigaction structure
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Enable extended signal information
    sa.sa_sigaction = handle_signal; // Use sa_sigaction for extended info

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        printf("An error has occurred!\n");
        exit(1);
    }

    printf("Waiting for SIGUSR1... PID is: %d\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}