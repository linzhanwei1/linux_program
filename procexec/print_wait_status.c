/* Listing 26-2 */
/** 
 * Dissect and print the process termination staus returned by wait() and related calls.
 */
#include <string.h>
#include <sys/wait.h>
#include "print_wait_status.h"
#include "tlpi_hdr.h"

/**NOTE: The following function employs printf(), which is not async-signal-safe(see Section 21.1.2).
 * As such, this function is also not async-signal-safe (i.e., beware of calling it from a SIGCHLD handler).
 */

/* Examine a wait() status using the W* macros */
void printWaitStatus(const char *msg, int status)
{
    if(NULL != msg)
        printf("%s", msg);
    
    if(WIFEXITED(status)){
        printf("child exited, status=%d\n", WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status)){
        printf("child killed by signal %d (%s)", WTERMSIG(status), strsignal(WTERMSIG(status)));
#ifdef WCOREDUMP
        if(WCOREDUMP(status))
            printf(" (core dumped");
#endif
        printf("\n");
    }
    else if(WIFSTOPPED(status)){
        printf("child stopped by signal %d (%s)\n", WSTOPSIG(status), strsignal(WSTOPSIG(status)));

#ifdef WIFCONTINUED
    }
    else if(WIFCONTINUED(status)){
        printf("child continued\n");
#endif
    }
    else{                   /* Should never happen */
        printf("what happened to this child? (status=%x)\n", (unsigned int)status);
    }
}