/**
 * File: signal_alarm.c
 * Modified by: Spencer Thacker <thackers@msoe.edu>
 * 
 * Brief summary of program:
 * Demonstrates the use of SIGALRM and a signal handler
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGALRM
void handle_alarm(int sig) {
    printf("SIGALRM received! The alarm has gone off.\n");
}

int main() {
    // Register the signal handler
    signal(SIGALRM, handle_alarm);

    // Set an alarm for 5 seconds
    printf("Setting an alarm for 5 seconds...\n");
    alarm(5);

    // Loop to keep the program alive
    while (1) {
        printf("Waiting for the alarm...\n");
        sleep(1);
    }

    return 0;
}
