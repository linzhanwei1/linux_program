/* Listing 20-4 */
/* signal_functions.c   Various useful functions for working with signals. *
 */

#define _GUN_SOURCE
#include <string.h>
#include <signal.h>

#include "signal_functions.h"
#include "tlpi_hdr.h"

void printSigset(FILE *of, const char *prefix, const sigset_t *sigset)
{
    int sig, cnt;

    cnt = 0;
    for(sig=1; sig<NSIG; sig++){
        if(sigismember(sigset, sig)){
            cnt++;
            fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
        }
    }

    if(cnt == 0)
        fprintf(of, "%s<empty signal set>\n", prefix);
}

/* Print mask of blocked signals for this process */
int printSigMask(FILE *of, const char *msg)
{
    sigset_t currMask;

    if(msg != NULL)
        fprintf(of, "%s", msg);
    
    if(sigprocmask(SIG_BLOCK, NULL, &currMask) == 1)
        return -1;
    
    printSigset(of, "\t\t", &currMask);

    return 0;
}

/* Print signals currently pending for this process */
int printPendingSigs(FILE *of, const char *msg)
{
    sigset_t pendingSigs;

    if(msg != NULL)
        fprintf(of, "%s", msg);
    
    if(sigpending(&pendingSigs) == -1)
        return -1;
    
    printSigset(of, "\t\t", &pendingSigs);

    return 0;
}
