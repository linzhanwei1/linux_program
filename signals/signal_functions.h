/* Header file for Listing 20-4 */
/* signal_functions.h Header file for signal_functions.c */

#ifndef __SIGNAL_FUNCTIONS_H__
#define __SIGNAL_FUNCTIONS_H__

#include <signal.h>
#include "tlpi_hdr.h"

int printSigMask(FILE *of, const char *msg);
int printPendingGigs(FILE *of, const char *msg);
void printSigset(FILE *of, const char *ldr, const sigset_t *mask);


#endif /* __SIGNAL_FUNCTIONS_H__ */