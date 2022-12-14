/* Listing 23-2 */
/*
 * timed_read.c Demonstrate the use of a timer to place a timeout on a blocking system call (read(2) in this case).
 */

#include <signal.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 200

/* SIGALARM handler: interrupts blocked system call */
static void handler(int sig)
{
    printf("Caught signal\n");
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    char buf[BUF_SIZE];
    ssize_t numRead;
    int savedErrno;

    if(argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [num-sec [restart-flag]]\n", argv[0]);
    
    /* Set up handler for SIGALRM. Allow system calls to be interrupted, unless second command-line argument was supplied. */
    sa.sa_flags = (argc > 2) ? SA_RESTART:0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    if(sigaction(SIGALRM, &sa, NULL) == -1)
        errExit("sigaction");
    
    alarm((argc > 1) ? getInt(argv[1], GN_NONNEG, "num-secs"):10);
    numRead = read(STDIN_FILENO, buf, BUF_SIZE);

    savedErrno = errno;         /* In case alarm() changes it */
    alarm(0);                   /* Ensure timer is turned off */
    errno = savedErrno;

    /* Determine result of read() */
    if(numRead == -1){
        if(errno == EINTR)
            printf("Read timed out\n");
        else
            errMsg("read");
    }
    else{
        printf("Successful read (%ld bytes): %.*s", (long)numRead, (int)numRead, buf);
    }

    exit(EXIT_SUCCESS);
}