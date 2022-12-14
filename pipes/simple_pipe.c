/* Listing 44-2 */
/* simple_pipe.c
 * Simple demonstration of the use of a pipe to communiccate between a parent and a child process.
 * Usage: simple_pipe "string"
 * The program creates a pipe, and then calls for() to create a child process. After the fork(), the 
 * parent writes the string given on the command line to the pipe, and the child uses a loop to read
 * data from the pipe and print it on standard output.
 */
#include <sys/wait.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 10

int main(int argc, char *argv[])
{
    int pfd[2];                     /* Pipe file descriptors */
    char buf[BUF_SIZE];
    ssize_t numRead;

    if(argc!=2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s string\n", argv[0]);
    if(pipe(pfd) == -1)             /* Create the pipe */
        errExit("pipe");
    
    switch(fork()){
        case -1:
            errExit("fork");
        
        case  0:                    /* child - reads from pipe */
            if(close(pfd[1]) == -1)
                errExit("close - child");
            
            while(1){               /* Read data from pipe, echo on stdout */
                numRead = read(pfd[0], buf, BUF_SIZE);
                if(numRead == -1)
                    errExit("read");
                if(numRead == 0)
                    break;
                if(write(STDOUT_FILENO, buf, numRead) != numRead)
                    fatal("child - partial/failed write");
            }

            write(STDOUT_FILENO, "\n", 1);
            if(close(pfd[0] == -1))
                errExit("close");
            _exit(EXIT_SUCCESS);
        
        default:                    /* Parent - writes to pipe */
            if(close(pfd[0]) == -1)
                errExit("close - parent");
            if(write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
                fatal("parent - partial/failed write");
            
            if(close(pfd[1]) == -1)
                errExit("close");
            
            wait(NULL);
            exit(EXIT_SUCCESS);
    }
}