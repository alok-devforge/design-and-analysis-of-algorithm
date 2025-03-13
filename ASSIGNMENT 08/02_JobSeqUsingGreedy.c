#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    int deadline;
    int profit;
} Job;
int cmpJob(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}
void jobSequencing(Job jobs[], int n)
{
    qsort(jobs, n, sizeof(Job), cmpJob);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    int *timeslot = (int *)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++)
    {
        timeslot[i] = -1;
    }
    int countJobs = 0;
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (timeslot[j] == -1)
            { 
                timeslot[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Number of jobs done: %d\n", countJobs);
    printf("Total profit: %d\n", totalProfit);
    printf("Job sequence: ");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (timeslot[i] != -1)
            printf("Job%d ", timeslot[i]);
    }
    printf("\n");
    free(timeslot);
}

int main()
{
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter job id, deadline, and profit for job #%d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    jobSequencing(jobs, n);
}