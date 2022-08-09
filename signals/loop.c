#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("This is a loop test procedure.\n");

    while(1){
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}