#include <stdio.h>
#include <stdlib.h>
#define N 100005
int n;
int priority[N],id[N],burst_time[N],arrival_time[N],waiting_time[N],computation_time[N],turn_around_time[N];

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int compare(int a_priority,int a_arrival_time,int b_priority,int b_arrival_time)
{
    if(a_priority < b_priority)
    {
        return -1;
    }
    else if(a_priority == b_priority)
    {
        if(a_arrival_time < b_arrival_time)
        {
            return -1;
        }
        else if(a_arrival_time == b_arrival_time)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
void sortProcesses(int *priorities, int *arrival_times, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (compare(priorities[j], arrival_times[j], priorities[j + 1], arrival_times[j + 1]) > 0)
            {
                swap(&priorities[j], &priorities[j + 1]);
                swap(&arrival_times[j], &arrival_times[j + 1]);
                swap(&id[j], &id[j + 1]);
                swap(&burst_time[j], &burst_time[j + 1]);
            }
        }
    }
}
void Priority()
{
    sortProcesses(priority, arrival_time, n);
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;
    double total_computation_time = 0.0;
    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            computation_time[i] = burst_time[i];
        }
        else
        {
            computation_time[i] = computation_time[i - 1] + burst_time[i];
        }
        turn_around_time[i] = computation_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
        total_computation_time+=computation_time[i];
        total_turn_around_time += turn_around_time[i];
    }
    printf("Processor ID\tPriority\tArrival Time\tBrust Time\tComputation Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",id[i],priority[i],arrival_time[i],burst_time[i],computation_time[i],turn_around_time[i],waiting_time[i]);
    }
    printf("Average Waiting Time: %.2lf\n", total_waiting_time / n);
    printf("Average Computation Time: %.2lf\n", total_computation_time / n);
    printf("Average Turn Around Time: %.2lf\n", total_turn_around_time / n);
}
int main()
{
    printf("Number of Processes: ");
    scanf("%d", &n);
    printf("Process Ids:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&id[i]);
    }
    printf("Process Burst Times:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst_time[i]);
    }
    printf("Process Arrival Times:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arrival_time[i]);
    }
    printf("Process Priorities:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&priority[i]);
    }
    Priority();
    return 0;
}
