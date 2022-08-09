/* Listing 15-2 */

/* t_chown.c

   Demonstrate the use of the chown() system call to change the owner
   and group of a file.

   Usage: t_chown owner group [file...]

   Either or both of owner and/or group can be specified as "-" to
   leave them unchanged.
*/

#include <pwd.h>
#include <grp.h>

#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    uid_t uid;
    gid_t gid;
    int i;
    Boolean errFnd;

    if(argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s owner group [file...\n]"
                 "          owner or group can be '-'"
                 "meaning leave unchanged\n", argv[0]);

    if(strcmp(argv[1], "-") == 0)
        uid = -1;
    else{
        uid = userIdFromName(argv[1]);
        if(uid == -1)
            fatal("No such user (%s)", argv[1]);
    }
    if(strcmp(argv[2], "-") == 0)
        gid = -1;
    else{
        gid = groupIdFromName(argv[2]);
        if(gid == -1)
            fatal("No group user (%s", argv[1]);
    }
    
    /* Change ownership of all files named in remaining arguments */
    errFnd = FALSE;
    for(i=3; i<argc; i++){
        if(chown(argv[i], uid, gid) == -1){
            errMsg("chown: %s", argv[i]);
            errFnd = TRUE;
        }
    }

    exit(errFnd ? EXIT_FAILURE:EXIT_SUCCESS);
}