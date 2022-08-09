#include <sys/stat.h>
#include <utime.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    char *pathname;
    struct stat sb;
    struct utimbuf utb;

    if(argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file\n", argv[0]);
    
    pathname = argv[1];

    if(stat(pathname, &sb) == -1)
        errExit("stat");
    
    utb.actime = sb.st_atime;
    utb.modtime = sb.st_atime;
    if(utime(pathname, &utb) == -1)
        errExit("utime");

    exit(EXIT_SUCCESS);
}