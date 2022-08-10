/* Listing 24-4 */
/*
 * t_vfork.c Demonstrate the use of vfork() to create a child process.
 */

#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int istack = 222;

    switch(vfork()){
        case -1:
            errExit("vfork");
        
        case  0:                    /* Child executes first, in parent's memory space */
            sleep(3);               /* Even if we sleep for a while, parent still is not scheduled */
            write(STDOUT_FILENO, "Child executing\n", 16);
            istack *= 3;            /* This change will be seen by parent */
            _exit(EXIT_SUCCESS);
        
        default:                    /* Parent is blocked untill chaild exits */
            write(STDOUT_FILENO, "Parent executing\n", 17);
            printf("istack=%d\n", istack);
            exit(EXIT_SUCCESS);
    }
}