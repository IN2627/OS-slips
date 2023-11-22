#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,int argv[])
{
pid_t pid=fork();
if(pid==0)
{
printf("\n i am child process");
printf("\n process id=%d\n",getpid());
return 0;
}
else if(pid>0)
{
printf("\n i am parent process");
printf("\n process id =%d",getpid());
}
else
{
printf("\n unable to create child process...");
}
return 0;
}