#include<bits/stdc++.h>
using namespace std;

/*
Burst Time = Time needed by the process to complete
Arrival Time = The time at which the process arrives in the main memory
Completion Time =  Time at which the procecss is completed according to the clock of the system
Turn Around Time = The actual time taken to complete the process
Waiting Time = Turn Around Time - Arrival Time
*/

void findWaitingTime(int processes[], int n, int bt[], int wt[], int time_quantum)
{
	int rem_bt[n];
	for (int i = 0; i < n; i++)
		rem_bt[i] = bt[i];

	int t = 0;

	while (1)
	{
		bool done = true;
		for (int i = 0; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false;
				if (rem_bt[i] > time_quantum)
				{
					t += time_quantum;
					rem_bt[i] -= time_quantum;
				}
				else
				{
					t += rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
			break;
	}

}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int time_quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt, time_quantum);

	findTurnAroundTime(processes, n, bt, wt, tat);

	for (int i = 0; i < n; i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];
	}

	cout << "Average waiting Time = " << (float)total_wt / (float)n << "\n";

	cout << "Average turn around time = " << (float)total_tat / (float)n;
}



int main()
{
	int processes[] = {1, 2, 3};
	int n = 3;
	int burst_time[] = {10, 5, 8};
	int time_quantum = 2;
	findavgTime(processes, n, burst_time, time_quantum);
	return 0;
}