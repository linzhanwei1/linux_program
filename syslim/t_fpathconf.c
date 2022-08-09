/* Listing 11-2 */
/**
 * Demonstrate the use of  fpathconf() to retrieve the values of pathname-related limits.
 */

#include "tlpi_hdr.h"

/* Print 'msg' plus sysconf() value for 'name' */
static void fpathconfPrint(const char *msg, int fd, int name)
{
    long lim;

    errno = 0;
    lim = fpathconf(fd, name);
    /* Call succeeded, limit determinate */
    if(lim != -1){
        printf("%s %ld\n", msg, lim);
    }
    else{
        if(errno == 0)             /* Call succeeded, limit indeterminate */
            printf("%s (indeterminate)\n", msg);
        else
            errExit("fpathconf %s", msg);
    }
}

int main(int argc, char *argv[])
{
    fpathconfPrint("_PC_NAME_MAX: ", STDIN_FILENO, _PC_NAME_MAX);
    fpathconfPrint("_PC_PATH_MAX: ", STDIN_FILENO, _PC_PATH_MAX);
    fpathconfPrint("_PC_PIPE_BUF: ", STDIN_FILENO, _PC_PIPE_BUF);

    exit(EXIT_SUCCESS);
}