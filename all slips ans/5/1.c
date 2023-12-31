// Write the simulation program for demand paging and show the page
//  scheduling and total number of page faults according the optimal page
//  replacement algorithm. Assume the memory of n frames.
// Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
/////////////////////////////////////////////////////////////////////////
//////////////
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
int get_pos(int tno)
{
    int i, tpos, cnt = 0, tframe[10];
    int temp = tno - 2;
    for (i = 0; i < nof; i++)
    {
        if (frame[i] == -1)
        {
            return i;
        }
        tframe[i] = frame[i];
    }
    for (; tno < nor; tno++)
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
        {
            return tpos;
        }
    }
    for (; temp >= 0; temp--)
    {
        for (i = 0; i < nof; i++)
        {
            if (tframe[i] == ref[temp])
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
void optimal()
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
            pos = get_pos(r + 1);
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
void display()
{
    int i, j;
    printf("\nReference String: ");
    for (i = 0; i < nor; i++)
    {
        printf("%2d", ref[i]);
    }
    printf("\n\n");
    for (i = 0; i < nof; i++)
    {
        for (j = 0; j < nor; j++)
        {
            printf("%2d", table[i][j]);
        }
        printf("\n");
    }
    printf("\n\nPage Fault= %d\n", pagefault);
}
int main()
{
    accept();
    optimal();
    display();
}