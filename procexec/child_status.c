/* Listing 26-3 */
/** child_status.c
 * Demonstrate the use of wait() and the W* macros for analyzing the child status returned by wait()
 * Usage: child_status [exit-status]
 * If "exit-status" is supplied, then the child immediately exits with this status. If no command-line arument is supplied
 * then the child loops waiting for signals that either cause it to stop or to terminate - both conditions can be detected and
 * differentiated by the parent. The parent process repeatedly waits on the child until it detects that the child either exited normally
 * or was killed bu a signal.
 */

#include <sys/wait.h>
#include "print_wait_status.h"
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int status;
    pid_t childPid;

    if(argc>1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [exit-status]\n", argv[0]);
    
    switch (fork()){
        case  -1:
            errExit("fork");
        
        case   0:           /* Child: either exits immediately with give status or loops waiting for signals */
            printf("Child started with PID = %ld\n", (long)getpid());
            if(argc > 1)                                /* Status supplied on command line? */
                exit(getInt(argv[1], 0, "exit-status"));
            else
                while(1)
                    pause();
            exit(EXIT_FAILURE);                         /* Not reached, but good parctice */
        
        default:                                        /* Parent: repeatedly wait on child until it either exits or is terminated by a signal */
            while(1){
                childPid = waitpid(-1, &status, WUNTRACED
#ifdef WCONTINUED           /* Not present on older version of Linux */
                                | WCONTINUED
#endif
                                    );
                if(childPid == -1)
                    errExit("waitpid");
                
                /* Print status in hex, and as separate decimal bytes */
                printf("waitpid() returned: PID=%ld; status=0x%04x (%d,%d)\n", (long)childPid, (unsigned int)status, status>>8, status&0xff);
                printWaitStatus(NULL, status);

                if(WIFEXITED(status) || WIFSIGNALED(status))
                    exit(EXIT_SUCCESS);
            }
    }
}