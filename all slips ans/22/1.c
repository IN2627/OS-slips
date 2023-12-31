// Write a C program that demonstrates the use of nice() system call. After
// a
//  child Process is started using fork (), assign higher priority to the
// child using
//  nice () system call.
/////////////////////////////////////////////////////////////////////////
///////////////
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("\nI am child process, id=%d\n", getpid());
        printf("\nPriority :%d,id=%d\n", nice(-7), getpid());
    }
    else
    {
        printf("\nI am parent process, id=%d\n", getpid());
        nice(1);
        printf("\nPriority :%d,id=%d\n", nice(15), getpid());
    }
    return 0;
}