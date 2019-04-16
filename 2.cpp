//Program No:1:Ques. 17. Design a scheduler following non-preemptive scheduling approach to schedule the processes that arrives at 
//different units and having burst time double the arrival time. Scheduler selects the process with largest burst time from the queue for 
//the execution. Process is not being preempted until it finishes its service time. Compute the average waiting time and average turnaround time.
 //What should be the average waiting time if processes are executed according to Shortest Job First scheduling approach with the same attribute values.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1000 // Maximum array size

int main()
{
    int p[MAX_SIZE]; // Declare an array of MAX_SIZE and Array p intialise the value of Arival Time
    int b[MAX_SIZE]; 
     int wt[MAX_SIZE]; 
    int tat[MAX_SIZE]; 
 int P[MAX_SIZE]; 
    int total=0,avg_wt,avg_tat;
     int i,pos,temp, j,N;
    

    /* Input the number of Process*/
    printf("Enter the number of Process:\n ");
    scanf("%d", &N);
//----------------------------------------------------------------------

    /* Input the value of Arrival time for Process */
    printf("\n Enter %d the value of Arrival time for Process- :\n ", N);
    for(i=0; i<N; i++)
    {
        scanf("%d", &p[i]);
    }

 //----------------------------------------------------------------------------
    //average waiting time is double the Arrival time.
    for(i=0; i<N; i++)
    {
      b[i]=2*(p[i]);
    }
//----------------------------------------------------------------------------
  /*To print the value of Burst time
    for(i=0; i<N; i++)
    {
        printf("%d, ", b[i]);
    }*/
//-------------------------------------------------------------------------------
    /*
     * Print the value of Arrival time for Process-
     *
    printf("\nElements in array are: ");
    for(i=0; i<N; i++)
    {
        printf("%d, ", p[i]);
    }*/
//----------------------------------------------------------------------------
//sorting for the burst values
for(i=0;i<N;i++)
    {
        pos=i;
        for(j=i+1;j<N;j++)
        {
            if(b[j]<b[pos])
                pos=j;
        }
 
        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 // To print the value of Burst time
printf("To Print the value of Burst time:-\n ");
    for(i=0; i<N; i++)
    {
        printf("\n%d ", b[i]);
    }
  printf("\n");
//-------------------------------------------------------------------------------
//calculate waiting time
    for(i=1;i<N;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=b[j];
 
        total+=wt[i];
    }
   avg_wt=(float)total/N;      //average waiting time
    total=0;
// To print the value of Waiting time
printf("To Print the value of Waiting time:-\n ");
    for(i=0; i<N; i++)
    {
        printf("\n%d",wt[i]);
    }
 
 //----------------------------------------------------------------------------
printf("\nProcess\t Arrival time\t    Burst Time    \tWaiting Time \tTurnaround Time");
    for(i=0;i<N;i++)
    {
        tat[i]=b[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d\t%d\n",P[i],p[i],b[i],wt[i],tat[i]);
    }
  //---------------------------------------------------
avg_tat=(float)total/N;
  printf("\n");
printf("The AVERAGE WAITNG TIME IS:-\n%d, ",avg_wt);
 printf("\nAverage Turnaround Time=\n%d",avg_tat);
printf("\nProgram done Thank you");
   //-----------------------------------------------
    
}
