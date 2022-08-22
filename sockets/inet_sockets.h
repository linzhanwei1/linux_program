/* Listing 59-8 */
/* inet_sockets.h
 * Header file for inet_sockets.c
 */
#ifndef INET_SOCKETS_H
#define INET_SOCKETS_H

#include <sys/socket.h>
#include <netdb.h>

int inetConnect(const char *host, const char *service, int type);
int inetListen(const char *service, int backlog, socklen_t *addlen);
int inetBind(const char *service, int type, socklen_t *addrlen);
char *inetAddressStr(const struct sockaddr *addr, socklen_t addrlen, char *addrStr, int addrStrLen);

#define IS_ADDR_STR_LEN 4096



#endif /* INET_SOCKETS_H */