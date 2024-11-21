/**
 * File: send_signal.c
 * Modified by: Spencer Thacker
 * 
 * Brief summary of program:
 * Waits for SIGUSR1 with data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // Convert the PID from the command-line argument
    pid_t pid = atoi(argv[1]);

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer
    int random_value = rand();
    printf("Sending value: %d to process %d\n", random_value, pid);

    // Prepare the sigval structure
    union sigval value;
    value.sival_int = random_value;

    // Send the signal with data
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        printf("An error has occurred!\n");
        exit(1);
    }

    return 0;
}