/* Listing 30-1 */
/* thread_incr.c
 * This program eploys two POSIX threads that increment the same global variable,
 * without using any synchronization method. As a consequence, updates are sometimes lost.
 */

#include <pthread.h>
#include "tlpi_hdr.h"

static volatile int glob = 0;       /* "volatile" prevents compiler optimizations of arithmetic operations on 'glob' */

static void *threadFunc(void *arg)
{
    int loops = *((int*)arg);
    int loc, i;

    for(i=0; i<loops; i++){
        loc = glob;
        loc++;
        glob = loc;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;

    loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops"):10000000;

    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if(s != 0)
        errExitEN(s, "pthread_create");
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if(s != 0)
        errExitEN(s, "pthread_create");
    
    s = pthread_join(t1, NULL);
    if(s != 0)
        errExitEN(s, "pthread_join");
    
    s = pthread_join(t2, NULL);
    if(s != 0)
        errExitEN(s, "pthread_join");
    
    printf("glob = %d\n", glob);

    exit(EXIT_SUCCESS);
}