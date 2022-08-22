/* Listing 57-8 */
/* us_abstract_bind.c
 * Demonstrate how to bind a UNIX domain socket to a name in the Linux-specific abstract namespace.
 * This program is Linux-specific.
 * The first printing of the book used slightly different code. The code was correct, but could have
 * been better. The old code is shown in comments below.
 */
#include <sys/un.h>
#include <sys/socket.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_un addr;
    char *str;

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;

    /* addr.sun_path[0] has already been set to 0 by memset() */
    str = "xyz";
    strncpy(&addr.sun_path[1], str, strlen(str));
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sockfd == -1)
        errExit("socket");
    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(sa_family_t)+strlen(str)+1) == -1)
        errExit("bind");
    
    sleep(60);
    exit(EXIT_SUCCESS);
}