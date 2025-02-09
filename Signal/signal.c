#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// Signal handler function for SIGUSR1 and SIGUSR2
static void sig_usr(int signo);

int main(void)
{
    // Set up signal handler for SIGUSR1
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        perror("can't catch SIGUSR1"); // Use perror for standard error output
        exit(1); // Exit with error code
    }
    // Set up signal handler for SIGUSR2
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        perror("can't catch SIGUSR2"); // Use perror for standard error output
        exit(1); // Exit with error code
    }

    for ( ; ; ) { // Infinite loop
        pause(); // Wait for a signal to be received
    }
    return 0; // Will not reach here in normal execution
}

// Signal handler function
static void sig_usr(int signo) // argument is signal number
{
    if (signo == SIGUSR1) {
        printf("received SIGUSR1\n");
    } else if (signo == SIGUSR2) {
        printf("received SIGUSR2\n");
    } else {
        fprintf(stderr, "received signal %d\n", signo); // Use fprintf to stderr for error/unexpected signals
        exit(1); // Exit in case of unexpected signal for simplicity in this example, or you can handle it differently
    }
}