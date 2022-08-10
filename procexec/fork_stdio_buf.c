/* Listing 25-2 */
/**
 * fork_stdio_buf.c
 * Experiment with fork() and stdio buffering.
 */

#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    printf("Hello world\n");
    write(STDOUT_FILENO, "Ciao\n", 5);

    if(fork() == -1)
        errExit("fork");
    
    /* Both child and parent continue execution here */
    exit(EXIT_SUCCESS);
}