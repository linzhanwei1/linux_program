/* Listing 57-2 */
/* us_xfr.h
 * Header file for us_xfr.c and us_xfr_cl.c.
 * These programs employ a socket in /tmp. This makes it easy to compile and run the programs. However, for a security
 * reasons, a real-world application should never create sensitive files in /tmp. (As a simple of example of th king of
 * security problems that can result, a malicious user could create a dile using the name defined in SV_SOCK_PATH, and thereby cause
 * a denial of service attack against this application. See section 38.7 of "THe linux Programming Interface" for more details
 * on this subject.)
 */
#include <sys/un.h>
#include <sys/socket.h>
#include "tlpi_hdr.h"

#define SV_SOCK_PATH    "/home/book/linux_program/sockets/us_xfr"
#define BUF_SIZE        100