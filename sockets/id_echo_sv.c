/* Listing 60-2 */
/* id_echo_sv.c
 * This program implements a deamon that provides the UDP "echo" service. It reads datagrams and then sends
 * sopies bck to the originating address.
 * NOTE: this program must be run under a root login, in order to allow the "echo" port (7) to be bound. Alternatively,
 * for test purposes, you can edit id_echo.h and replace the SERVICE name with a suitable unreserved port number (e.g., "51000")
 * and make a corresponding change in the client.
 * See also id_echo_cl.c.
 */
#include <syslog.h>
#include "id_echo.h"
#include "become_daemon.h"

int main(int argc, char *argv[])
{
    int sfd;
    ssize_t numRead;
    socklen_t len;
    struct sockaddr_storage claddr;
    char buf[BUF_SIZE];
    char addrStr[IS_ADDR_STR_LEN];

    if(becomeDaemon(0) == -1)
        errExit("becomeDaemon");
    
    sfd = inetBind(SERVICE, SOCK_DGRAM, NULL);
    if(sfd == -1){
        syslog(LOG_ERR, "Could not create server socket (%s)", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Receive datagrams and return copies to senders */
    while(1){
        len = sizeof(struct sockaddr_storage);
        numRead = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr *)&claddr, &len);
        if(numRead == -1)
            errExit("recvfrom");
        if(sendto(sfd, buf, numRead, 0, (struct sockaddr *)&claddr, len) != numRead)
            syslog(LOG_WARNING, "Error echoing response to %s (%s)", inetAddressStr((struct sockaddr *)&claddr, len, addrStr, IS_ADDR_STR_LEN), strerror(errno));
    }
}