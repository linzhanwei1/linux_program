#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int fd;

    if(argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file\n", argv[0]);
    
    fd = open(argv[1], O_WRONLY);       /* Open 1: check if file exists */
    if(fd != -1){
        printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(), argv[1]);
        close(fd);
    }
    else{
        if(errno != ENOENT){
            errExit("open");        /* Failed for unexpected reason */
        }
        else{
            printf("[PID %ld] File \"%s\" doesn't exist yet\n", (long)getpid(), argv[1]);
            if(argc > 2){           /* Delay between check and create */
                sleep(5);           /* Suspend execution for 5 seconds */
                printf("[PID %ld] Done sleeping\n", (long)getpid());
            }
            fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
            if(-1 == fd)
                errExit("open");
            printf("[PID %ld] Created file \"%s\" exclusively\n", (long)getpid(), argv[1]);
        }
    }

    exit(EXIT_SUCCESS);
}