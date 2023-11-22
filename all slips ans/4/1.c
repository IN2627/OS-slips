// Write the simulation program for demand paging and show the page
//  scheduling and total number of page faults according the MFU page
//  replacement algorithm. Assume the memory of n frames.
// Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
/////////////////////////////////////////////////////////////////////////
///////////////////////
#include <stdio.h>
int nor, nof, table[20][20], ref[20], frame[10], count[10], pagefault = 0;
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
int get_pos(int pos)
{
    int max, i, tpos;
    tpos = pos;
    max = count[pos];
    i = pos;
    do
    {
        if (frame[i] == -1)
            return i;
        if (count[i] > max)
        {
            max = count[i];
            tpos = i;
        }
        i = (i + 1) % nof;
    } while (i != pos);
    return tpos;
}
void mfu()
{
    int i, pos = 0, r, found;
    for (i = 0; i < nof; i++)
    {
        frame[i] = -1;
        count[i] = -1;
    }
    for (r = 0; r < nor; r++)
    {
        found = search(ref[r]);
        if (found == -1)
        {
            pos = get_pos(pos);
            frame[pos] = ref[r];
            count[pos] = 1;
            pos = (pos + 1) % nof;
            pagefault++;
            for (i = 0; i < nof; i++)
            {
                table[i][r] = frame[i];
            }
        }
        else
        {
            count[found]++;
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
    mfu();
    display();
}