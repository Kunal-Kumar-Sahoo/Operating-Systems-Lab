#include <stdio.h>

int main() {
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
	float avg_wt, avg_tat;

	printf("Enter number of processes: ");
	scanf("%d", &n);

	printf("Enter burst times:\n");
	for(i = 0; i < n; ++i) {
		printf("p[%d]: ", i+1);
		scanf("%d", bt+i);
		p[i] = i+1;
	}

	// sorting of burst times
	for(i = 0; i < n; ++i) {
		pos = i;
		for(j = i+1; j < n; ++j) 
			if(bt[j] < bt[pos])
				pos = j;
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0;

	// finding the waiting time of all the processes
	for(i = 1; i < n; ++i) {
		wt[i] = 0;
		for(j = 0; j < i; ++j)
			// individual WT by adding BT of all previous completed processes
			wt[i] += bt[j];
		// total waiting time
		total += wt[i];
	}

	// average waiting time
	avg_wt = (float)total / n;

	printf("\nProcess\t Burst Time \tWaiting Time \tTurn Around Time:");
	for(i = 0; i < n; ++i) {
		// turn around time of individual processes
		tat[i] = bt[i] + wt[i];
		// total turn around time
		totalT += tat[i];
		printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}

	// average turn around time
	avg_tat = (float)totalT / n;
	printf("\n\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
	
	return 0;
}