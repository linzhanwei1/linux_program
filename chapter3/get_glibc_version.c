#include <stdio.h>
#include <gnu/libc-version.h>
#include <stdlib.h>

int main(void)
{
    printf("Glibc version:%s\n", gnu_get_libc_version());

    exit(0);
}