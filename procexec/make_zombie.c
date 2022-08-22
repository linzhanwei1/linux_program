/* Listing 26-4 */
/*
 * Demonstrate how a child process becomes a zombie in the interval between the time it exits, and the time its parent 
 * performs a wait (or exits, at which time it is adopted by init(8), which does a wait, thus releasing the zombie).
 */

#include <signal.h>
#include <libgen.h>
#include "tlpi_hdr.h"

#define CMD_SIZE 200

int main(int argc, char *argv[])
{
    char cmd[CMD_SIZE];
    pid_t childPid;

    setbuf(stdout, NULL);       /* Disable buffering of stdout */
    printf("Parent PID=%ld\n", (long)getpid());

    switch(childPid = fork()){
        case -1:
            errExit("fork");
        
        case  0:                /* Child: immediately exits to become zombie */
            printf("Child (PID=%ld) exiting\n", (long)getpid());
            _exit(EXIT_SUCCESS);
        
        default:                /* Parent */
            sleep(3);
            snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
            system(cmd);        /* View zombie child */

            /* Now send the "sure kill" signalto the zombie */
            if(kill(childPid, SIGKILL) == -1)
                errMsg("kill");
            sleep(3);           /* Give child a chance to react to signal */
            printf("After sending SIGKILL to zombie (PID=%ld):\n", (long)childPid);
            system(cmd);
            
            exit(EXIT_SUCCESS);
    }
}