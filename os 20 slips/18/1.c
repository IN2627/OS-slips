#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    int pid, retnice;
    printf("press DEL to stop process \n");
    pid = fork();
    for (;;)
    {
        if (pid == 0)
        {
            retnice = nice(-5);
            printf("\n child gets higher CPU priority % d", retnice);
            sleep(1);
        }
        else
        {
            retnice = nice(4);
            printf("\n parent gets lower CPU priority % d", retnice);
            sleep(1);
        }
    }
    return 0;
}