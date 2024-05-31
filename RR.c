#include <stdio.h>
#define N 100005
int n,quantum_time;
int id[N],burst_time[N],arrival_time[N],waiting_time[N],computation_time[N],turn_around_time[N],remaining_time[N];

void RoundRobin()
{
    int complete,current_time,change;
    double total_waiting_time=0.0;
    double total_turn_around_time=0.0;
    double total_computation_time=0.0;

    for(int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    complete=0;
    current_time=0;

    while (complete < n)
    {
        change = 0;
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i]<=current_time && remaining_time[i]>0)
            {
                if (remaining_time[i]<=quantum_time)
                {
                    complete++;
                    current_time+=remaining_time[i];

                    computation_time[i]=current_time;
                    turn_around_time[i]=computation_time[i] - arrival_time[i];
                    waiting_time[i]=turn_around_time[i] - burst_time[i];

                    total_waiting_time+=waiting_time[i];
                    total_computation_time+=computation_time[i];
                    total_turn_around_time+=turn_around_time[i];

                    remaining_time[i] = 0;
                }
                else
                {
                    current_time += quantum_time;
                    remaining_time[i] -= quantum_time;
                }
                change++;
            }
        }
        if (change == 0)
        {
            current_time++;
        }
    }
    printf("Processor ID\tArrival Time\tBrust Time\tComputation Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",id[i],arrival_time[i],burst_time[i],computation_time[i],turn_around_time[i],waiting_time[i]);
    }
    printf("Average Waiting Time: %.2lf\n", total_waiting_time / n);
    printf("Average Computation Time: %.2lf\n", total_computation_time / n);
    printf("Average Turn Around Time: %.2lf\n", total_turn_around_time / n);
}

int main()
{
    printf("Number of Processes: ");
    scanf("%d",&n);
    printf("Quantum time: ");
    scanf("%d",&quantum_time);
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
    RoundRobin();
    return 0;
}

