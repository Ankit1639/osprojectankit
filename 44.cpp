//Develop a scheduler which submits processes to the processor in the following scenario and compute the scheduler performance by providing the 
//waiting time for process, turnaround time for process and average waiting time and turnaround time.
//Considering the arrival time and burst time requirement of the process the scheduler schedules the processes by interrupting the processor 
//after every 6 units of time and does consider the completion of the process in this iteration. The scheduler then checks for the number of process 
//waiting for the processor and allots the processor to the process but interrupting the processor every 10 unit of time and considers the completion 
//of the processes in this iteration. The scheduler checks the number of processes waiting in the queue for the processor after the second iteration and 
//gives the processor to the process which needs more time to complete than the other processes to go in the terminated state.


#include<iostream> 
#include<stdio.h>
#include<conio.h>
using namespace std; 
  
// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, 
             int bt[], int wt[], int quantum,int quantum1) 
{ 
    // Make a copy of burst times bt[] to store remaining 
    // burst times. 
    int rem_bt[n];  
     int q=quantum;
     int q1=quantum1;
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
  
    int t = 0; // Current time 
  
    // Keep traversing processes in round robin manner 
    // until all of them are not done. 
    while (1) 
    { 
        bool done = true; 
  
        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < n; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 
  
                if (rem_bt[i] > q) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += q; 
  
                    // Decrease the burst_time of current process 
                    // by quantum 
                    rem_bt[i] -= q; 
                } 
  
                // If burst time is smaller than or equal to 
                // quantum. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
  
                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
  
        // If all processes are done 
        if (done == true) 
          break; 
	  else
	  {
		  for (int i = 0 ; i < n; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 
  
                if (rem_bt[i]>q1) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += q1; 
  
                    // Decrease the burst_time of current process 
                    // by quantum 
                    rem_bt[i] -= q1; 
                } 
  
                // If burst time is smaller than or equal to 
                // quantum. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
  
                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
	  }
	  if (done == true) 
          break; 
	  else
                {  for(int i=0;i<n;i++)
                    {
					  if(rem_bt[i] > rem_bt[i+1])
                        {
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
  
                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0;
                    } 
                } 
            }
                 if (done == true) 
                 break; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
                        int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
// Function to calculate average time 
void findavgTime(int processes[], int n, int bt[], 
                                     int quantum,int quantum1) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    // Function to find waiting time of all processes 
    findWaitingTime(processes, n, bt, wt, quantum,quantum1); 
  
    // Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, bt, wt, tat); 
  
    // Display processes along with all details 
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
// Main code:
int main() 
{ 
    // process no: 
    
    int processes[] = { 1, 2, 3}; 
    int n = sizeof processes / sizeof processes[0]; 
    int a[n];
    cout<<"Enter the value of arrival time:\n";
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
   }
    // Burst time of all processes 
    int burst_time[n]; 
    cout<<"Enter the value of Burst time:\n";
      for(int i=0;i<n;i++)
    {
    cin>>burst_time[i];
     }
    int quantum,quantum1; 
    //Both  Time quantum's
	cout<<"Enter the value of Time Quantum";
	cin>>quantum;
    cout<<"Enter the value of Time Quantum1";
	cin>>quantum1;
   //for finding the Average Time of Process
    findavgTime(processes, n, burst_time, quantum,quantum1); 
    return 0; 
} 
