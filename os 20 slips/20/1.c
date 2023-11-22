#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void bubblesort()
{
    int i, j, a[50], n, temp;
    printf("\n bubble sort \n");
    printf("enter size of array\t");
    scanf("%d", &n);
    printf("\n enter %d element", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n sorted array is \t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
int insertionsort()
{
    int n, i, j, temp;
    int arr[64];
    printf("enter number of element");
    scanf("%d", &n);
    printf("enter %d element\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("sorted list in ascending order\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
int main()
{
    if (fork() == 0)
    {
        insertionsort();
    }
    else
    {
        wait(NULL);
        bubblesort();
    }
    return 0;
}
