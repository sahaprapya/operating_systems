#include<stdio.h>
int main()
{
    int processor_id[100],n;
    int at[100],bt[100],wt[100],tat[100],ct[100],sum=0,act=0,atat=0,awt=0;
    float CT,WT,TAT;
    printf("Enter number of processors: ");
    scanf("%d",&n);
    printf("Enter processor id of all processors:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processor_id[i]);
    }
    printf("Enter arrival time of all processor: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter brust time of all processor: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    //CT Calculation
    for(int i=0;i<n;i++)
    {
        sum+=bt[i];
        ct[i]=sum;
        act+=ct[i];
    }
    //TAT Calculation
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        atat+=tat[i];
    }
    //WT Calculation
    for(int i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        awt+=wt[i];
    }
    printf("Processor ID\tArrival Time\tBrust Time\tComputation Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",processor_id[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    CT=(act*1.0)/n;
    TAT=(atat*1.0)/n;
    WT=(awt*1.0)/n;
    printf("Average Computation Time: %.2f\n",CT);
    printf("Average Turn Around Time: %.2f\n",TAT);
    printf("Average Waiting Time: %.2f\n",WT);
    return 0;
}
