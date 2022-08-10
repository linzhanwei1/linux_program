/* Listing 26-1 */
/**
 * multi_wait.c
 * Demonstrate the use of wait(2): create multiple children and then wait for them all.
 * Usage: multi_wait sleep-time...
 * One child process is created for each command-line argument. Each child sleeps for the
 * number of seconds specified in the corresponding command-line argument before exiting.
 * After all children have been created, the parent loops, waiting for terminated children,
 * and displaying theri PIDs.
 */

#include <sys/wait.h>
#include <time.h>
#include "curr_time.h"
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int numDead;                /* Number of children so far waited for */
    pid_t childPid;             /* Pid of waited for child */
    int i;

    if(argc<2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s sleep-time...\n", argv[0]);
    
    setbuf(stdout, NULL);       /* Disable buffering of stdout */

    for(i=1; i<argc; i++){      /* Create one child for each argument */
        switch(fork()){
            case -1:
                errExit("fork");
            
            case  0:
                printf("[%s] child %d started with PID %ld, sleeping %s seconds\n", currTime("%T"), i, (long)getpid(), argv[i]);
                sleep(getInt(argv[i], GN_NONNEG, "sleep-time"));
                _exit(EXIT_SUCCESS);
            
            default:            /* Parent just continues around loop */
                break;
        }
    }

    numDead = 0;
    while(1){                   /* Parent waits for each child to exit */
        childPid = wait(NULL);
        if(childPid == -1){
            if(errno == ECHILD){
                printf("No more children - bye!\n");
                exit(EXIT_SUCCESS);
            }
            else{               /* Some other (unexpected) error */
                errExit("wait");
            }
        }

        numDead++;
        printf("[%s] wait() returned child PID %ld (numDead=%d\n", currTime("%T"), (long)childPid, numDead);
    }
}