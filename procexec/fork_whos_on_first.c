/* Listing 24-5 */
/*
 * Parent repeatedly creates a child, and then processes both race to be the first to print a message.
 * (Each child terminates after printing its mssage.)The results of running this program give us an idea of which
 * of the two processes--parent or child--is usually scheduled first after a fork().
 * Whether the child or the parent is scheduled first after fork() has changed a number of times across different kernel version.
 */

#include <sys/wait.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int numChildren, i;
    pid_t childPid;

    if(argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [bun-children]\n", argv[0]);
    
    numChildren = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-children"):1;
    setbuf(stdout, NULL);           /* Make stdout unbuffered */
    for(i=0; i<numChildren; i++){
        switch(childPid = fork()){
            case -1:
                errExit("fork");
            
            case  0:
                printf("%d child\n", i);
                _exit(EXIT_SUCCESS);
            
            default:
                printf("%d parent\n", i);
                wait(NULL);         /* Wait for child to terminate */
                break;
        }
    }

    exit(EXIT_SUCCESS);
}