/* Listing 20-1 */
/**
 * Catch the SIGINT signal, generatedd by typing control-C (^C).
 * Note that although we use signal() to establish the signal handler in this program, the
 * use of sigaction() is always preferable for this task.
 */

#include <signal.h>
#include "tlpi_hdr.h"

static void sigHandler(int sig)
{
    printf("Ouch!\n");
}

int main(int argc, char *argv[])
{
    int i;

    if(signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");
    

    while(1){
        printf("%d\n", ++i);
        sleep(3);
    }
}