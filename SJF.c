#include<stdio.h>
#include<limits.h>
#define N 100005
int n;
int id[N];
int burst_time[N];
int arrival_time[N];
int waiting_time[N];
int computation_time[N];
int turn_around_time[N];

void SJF()
{
    int complete=0;
    int current_time=0;
    int index,minimum;
    double total_waiting_time=0.0;
    double total_turn_around_time=0.0;
    double total_computation_time=0.0;
    index=-1;
    minimum=INT_MAX;
    while(complete<n)
    {
        index=-1;
        minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arrival_time[i]<=current_time && computation_time[i] == 0)
            {
                if(burst_time[i]<minimum)
                {
                    index=i;
                    minimum=burst_time[i];
                }
            }
        }
        if (index!=-1)
        {
            complete++;
            current_time+=burst_time[index];
            computation_time[index]=current_time;
            turn_around_time[index]=computation_time[index] - arrival_time[index];
            waiting_time[index]=turn_around_time[index] - burst_time[index];
            total_computation_time+=computation_time[index];
            total_waiting_time+=waiting_time[index];
            total_turn_around_time+=turn_around_time[index];
        }
        else
        {
            current_time++;
        }
    }
    printf("Processor ID\tArrival Time\tBrust Time\tComputation Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",id[i],arrival_time[i],burst_time[i],computation_time[i],turn_around_time[i],waiting_time[i]);
    }
    printf("Average Waiting Time: %.2lf\n",total_waiting_time/n);
    printf("Average Turn Around Time: %.2lf\n",total_turn_around_time/n);
    printf("Average computation Time: %.2lf\n",total_computation_time/n);
}
int main()
{
    printf("Number of Processes: ");
    scanf("%d",&n);
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
    SJF();
    return 0;
}
