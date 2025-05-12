#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    char id;
    int profit;
    int deadline;
} job;
int comapre(const void *a,const void *b)
{
    return ((job *)b)->profit - ((job *)a)->profit;
}
void jobSequencing(job jobs[],int n)
{
    qsort(jobs,n,sizeof(job),comapre);
    int slot[n];
    char result[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=0;
        result[i]='\0';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=(jobs[i].deadline < n?jobs[i].deadline:n)-1;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                result[j]=jobs[j].id;
                break;
            }
        }
    }
    int total_profit=0;
    printf("Scheduled jobs: \n");
    for (int i = 0; i < n; i++)
    {
        if (result[i] != '\0')
        {
            printf("%c ", result[i]);
            for (int k = 0; k < n; k++)
            {
                if (jobs[k].id == result[i])
                {
                    total_profit += jobs[k].profit;
                    break;
                }
            }
        }
    }
    printf("\nTotal profit is :%d ",total_profit);    
}
int main()
{
    job jobs[] = {
        {'a', 20, 2},
        {'b', 15, 2},
        {'c', 10, 1},
        {'d', 5, 3},
        {'e', 1, 3}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
}