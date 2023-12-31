// *************************************************************************
// *************
// Write a C program to implement the toy shell. It should display the
// command
// prompt â€œmyshell$â€ù. Tokenize the command line and execute the given
//  command by creating the child process. Additionally it should interpret
// the
//  following commands.
//  count c filename :- To print number of characters in the file.
//  count w filename :- To print number of words in the file.
//  count l filename :- To print number of lines in the file.
/////////////////////////////////////////////////////////////////////////
////////////

#include <stdio.h>
int nor, nof, table[20][20], ref[20], frame[10], pagefault = 0;
void accept()
{
    int i;
    printf("\nHow many references:");
    scanf("%d", &nor);
    printf("\nEnter reference String:");
    for (i = 0; i < nor; i++)
    {
        scanf("%d", &ref[i]);
    }
    printf("\nHow many Frames:");
    scanf("%d", &nof);
}
int search(int pno)
{
    int i;
    for (i = 0; i < nof; i++)
    {
        if (frame[i] == pno)
            return i;
    }
    return -1;
}
void display()
{
    int i, j;
    printf("\nReference String: ");
    for (i = 0; i < nor; i++)
    {
        printf("%2d ", ref[i]);
    }
    printf("\n\n");
    for (i = 0; i < nof; i++)
    {
        for (j = 0; j < nor; j++)
        {
            printf("%2d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n\nPage Fault= %d\n", pagefault);
}
int get_pos(int tno)
{
    int i, tpos, cnt = 0, tframe[10];
    for (i = 0; i < nof; i++)
    {
        if (frame[i] == -1)
        {
            return i;
        }
        tframe[i] = frame[i];
    }
    for (; tno >= 0; tno--)
    {
        for (i = 0; i < nof; i++)
        {
            if (tframe[i] == ref[tno])
            {
                tpos = i;
                cnt++;
                tframe[i] = -1;
                break;
            }
        }
        if (cnt == nof)
            return tpos;
    }
}
void lru()
{
    int i, pos = 0, r, found;
    for (i = 0; i < nof; i++)
    {
        frame[i] = -1;
    }
    for (r = 0; r < nor; r++)
    {
        found = search(ref[r]);
        if (found == -1)
        {
            pos = get_pos(r - 1);
            frame[pos] = ref[r];
            pos = (pos + 1) % nof;
            pagefault++;
            for (i = 0; i < nof; i++)
            {
                table[i][r] = frame[i];
            }
        }
        else
        {
            for (i = 0; i < nof; i++)
            {
                table[i][r] = frame[i];
            }
        }
    }
}
int main()
{
    accept();
    lru();
    display();
}