/*
Demonstration Commands
gcc -o signal_handler signal_handler.c
./signal_handler
ps -e | grep signal_handler
kill -SIGINT <PID>
kill -SIGKILL
*/

/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Spencer Thacker <thackers@msoe.edu>
 * 
 * Brief summary of modifications:
 * Commented out the signal handler for SIGINT to prevent the program from exiting
 * Added a committed section with demonstration commands
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    //exit(1)
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}