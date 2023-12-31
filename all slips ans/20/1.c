// Write a C program to implement the shell which displays the command
//  prompt “myshell$”. It accepts the command, tokenize the command line and
//  execute it by creating the child process. Also implement the additional
//  command ‘typeline’ as
//  typeline -a filename :- To print all lines in the file.
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
void typeline(char *p1, char *fname)
{
    int handle, n, lcnt;
    char ch;

    handle = open("a.txt", O_RDONLY);

    if (handle == -1)
    {
        printf("\n File %s Not Found....", fname);
    }
    else
    {

        if (strcmp(p1, "a") == 0)
        {
            printf("\nContents of FILE=%s\n", fname);
            while (read(handle, &ch, 1))
            {
                printf("%c", ch);
            }
            close(handle);
        }
        else
        {
            n = atoi(p1);
            lcnt = 0;
            if (n > 0)
            {
                printf("Displaying First %d lines of file\n", n);
                while (read(handle, &ch, 1))
                {
                    printf("%c", ch);
                    if (ch == '\n')
                        lcnt++;
                    if (lcnt == n)
                        break;
                }
                close(handle);
            }
            else
            {
                n = -n;
                printf("Displaying Last %d lines of file\n", n);
                while (read(handle, &ch, 1))
                {
                    if (ch == '\n')
                        lcnt++;
                }

                n = lcnt - n;
                lcnt = 0;
                lseek(handle, 0, SEEK_SET);
                while (read(handle, &ch, 1))
                {
                    if (ch == '\n')
                        lcnt++;
                    if (lcnt == n)
                        break;
                }
                while (read(handle, &ch, 1))
                {
                    printf("%c", ch);
                }
                close(handle);
            }
        }
    }
}
int main()
{
    char cmd[80], tok1[10], tok2[10], tok3[10], tok4[10];
    int n;
    while (1)
    {
        printf("\nMYSHELL $]");
        fgets(cmd, 80, stdin);
        n = sscanf(cmd, "%s%s%s%s", tok1, tok2, tok3, tok4);
        switch (n)
        {
        case 1:
            if (fork() == 0)
            {
                execlp(tok1, tok1, NULL);
            }
            wait(0);
            break;
        case 2:
            if (fork() == 0)
            {
                execlp(tok1, tok1, tok2, NULL);
            }
            wait(0);
            break;
        case 3:
            if (strcmp(tok1, "typeline") == 0)
            {
                typeline(tok2, tok3);
            }
            else
            {
                if (fork() == 0)
                {

                    execlp(tok1, tok1, tok2, tok3, NULL);
                }
                wait(0);
            }
            break;
        case 4:
            if (fork() == 0)
            {

                execlp(tok1, tok1, tok2, tok3, tok4, NULL);
            }
            wait(0);
            break;
        }
    }
}