/* Listing 59-1 */
/* read_line.c Implementation of readLine(). */
#include <unistd.h>
#include <errno.h>
#include "read_line.h"          /* Declaration of readline() */

/* Read characters from 'fd' until a newline is encountered. If a newline character is not encountered in the first (n-1) byte,
 * then the excess characters are discarded. The returned string placed in 'buf' is null-terminated and includes the newline 
 * character if it was read in the first (n-1) bytes. The function return value is the number of bytes placed in buffer
 */

ssize_t readLine(int fd, void *buffer, size_t n)
{
    ssize_t numRead;            /* # of bytes fetched by last read() */
    size_t totRead;             /* Total bytes read so far */
    char *buf;
    char ch;

    if(n <=0 || buffer == NULL){
        errno = EINVAL;
        return -1;
    }

    buf = buffer;               /* No pointer arithmetic on "void *" */
    totRead = 0;

    while(1){
        numRead = read(fd, &ch, 1);
        if(numRead == -1){
            if(errno == EINTR)  /* Interrupted --> restart read() */
                continue;
            else
                return -1;
        }
        else if(numRead == 0){  /* EOF */
            if(totRead == 0)    /* No bytes read; return 0 */
                return 0;
            else
                break;
        }
        else{                   /* 'numRead' must be 1 if we get here */
            if(totRead < n-1){   /* Discard > (n-1) bytes */
                totRead++;
                *buf++ = ch;
            }
            if(ch == '\n')
                break;
        }
    }

    *buf = '\0';

    return totRead;
}