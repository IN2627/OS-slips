// Write a C Program to create a child process using fork (), display parent
// and
//  child process id. Child process will display the message “I am Child
// Process”
//  and the parent process should display “I am Parent Process”
// .
/////////////////////////////////////////////////////////////////////////
///////

int main()
{
    int pid = fork();
    if (pid > 0)
    {
        printf("I am Parent process\n");
        printf("ID : %d\n\n", getpid());
    }
    else if (pid == 0)
    {
        printf("I am Child process\n");
        printf("ID: %d\n", getpid());
    }
    else
    {
        printf("Failed to create child process");
    }
    return 0;
}