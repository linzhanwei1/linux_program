/* Listing 60-1 */
/* id_echo.h
 * Header file for id_echo_sv.c and id_echo_cl.c.
 */
#include "inet_sockets.h"
#include "tlpi_hdr.h"

#define SERVICE     "echo"          /* Name of UDP service */
#define BUF_SIZE    500             /* Maximum size of datagrams that can be read by client and server */
