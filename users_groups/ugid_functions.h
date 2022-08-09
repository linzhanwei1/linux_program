/* Header file for Listing 8-1 */
/* ugid_functions.h
 * Header file for ugid_functions.c
 */

#ifndef __UGID_FUNCTIONS_H__
#define __UGID_FUNCTIONS_H__

#include "tlpi_hdr.h"

char *userNameFromId(uid_t uid);
uid_t userIdFromName(const char *name);
char *groupNameFromId(gid_t gid);
gid_t groupIdFromName(const char *name);


#endif /* __UGID_FUNCTIONS_H__ */