// *************************************************************************
// ****************
// Write the program to simulate Non-preemptive Shortest Job First (SJF) –
//  scheduling. The arrival time and first CPU-burst of different jobs
// should be
//  input to the system. Accept no. of Processes, arrival time and burst
// time. The
//  output should give Gantt chart, turnaround time and waiting time for
// each
//  process. Also find the average waiting time and turnaround time
/////////////////////////////////////////////////////////////////////////
/////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process_info
{
    char pname[10];
    int AT, BT, TBT, CT, TAT, WT;
};
struct process_info p[10];
struct gantt_chart
{
    int ST, ET;
    char pname[10];
};
struct gantt_chart g[100];
int n, gcnt = 0, totalTAT, totalWT;
void accept()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter process: ");
        scanf("%s", p[i].pname);
        printf("\nEnter Arrival Time:");
        scanf("%d", &p[i].AT);
        printf("\nEnter Burst Time:");
        scanf("%d", &p[i].BT);
        p[i].TBT = p[i].BT;
    }
    printf("\n");
}
void sort_AT()
{
    int i, j;
    struct process_info t;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (p[j].AT > p[j + 1].AT)
            {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}
void fcfs()
{
    int time = 0, i;
    for (i = 0; i < n;)
    {
        if (p[i].AT <= time && p[i].TBT != 0)
        {
            g[gcnt].ST = time;
            strcpy(g[gcnt].pname, p[i].pname);
            g[gcnt].ET = time + p[i].TBT;
            gcnt++;
            time = time + p[i].TBT;
            p[i].TBT = 0;
            i++;
        }
        else
        {
            g[gcnt].ST = time;
            strcpy(g[gcnt].pname, "CPU IDLE");
            g[gcnt].ET = time + 1;
            gcnt++;
            time++;
        }
    }
}
void calculate()
{
    int ct = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < gcnt; j++)
        {
            if (strcmp(p[i].pname, g[j].pname) == 0)
            {
                ct = g[j].ET;
            }
        }
        p[i].CT = ct;
    }
    for (i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        totalTAT = totalTAT + p[i].TAT;
        totalWT = totalWT + p[i].WT;
    }
}
void display()
{
    int i = 0;
    printf("\nInformation of System Info\n");
    printf("\nPname\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t%d\t%d\t%d\t%d\t%d", p[i].pname, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\n\nGantt Chart=");
    for (i = 0; i < gcnt; i++)
    {
        printf("|%d|%s|%d|\t", g[i].ST, g[i].pname, g[i].ET);
    }
    printf("\nTotal TAT=%d", totalTAT);
    printf("\nTotal WT=%d", totalWT);
    printf("\nAverage TAT=%f", (float)(totalTAT / n));
    printf("\nAverage WT=%f", (float)(totalWT / n));
}
void acceptSystemBT()
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].BT = (rand() % 10) + 1;
        p[i].TBT = p[i].BT;
    }
}
int main()
{
    int i;
    printf("How many processes you have: ");
    scanf("%d", &n);
    printf("\nExecuting user Given Burst Time For FCFS.....\n");
    accept();
    printf("\nPname\tAT\tBT");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t%d\t%d", p[i].pname, p[i].AT, p[i].BT);
    }
    printf("\n");
    sort_AT();
    fcfs();
    calculate();
    display();
    printf("\n");
    printf("\nExecuting System Given Burst Time For FCFS.....\n");
    acceptSystemBT();
    printf("\nPname\tAT\tBT");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t%d\t%d", p[i].pname, p[i].AT, p[i].BT);
    }
    printf("\n");
    sort_AT();
    fcfs();
    calculate();
    display();
    printf("\n");
}