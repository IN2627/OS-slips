#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid > 0)
    {
        printf("\n parent process");
        printf("process id = % d \n", getpid());
    }
    else if (pid == 0)
    {
        printf("\n child process");
        printf("process id = % d\n", getpid());
        printf("parent ID = % d\n", getppid());
        Sleep(10);
        printf("\n child process");
        printf("process id = % d\n", getpid());
        printf("parent ID = % d\n", getppid());
    }
    else
    {
        printf("failed to create child process..");
    }
    return 0;
}
