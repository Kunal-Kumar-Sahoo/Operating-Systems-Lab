#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Enter the number of processes: ");
	int n; scanf("%d", &n);

	int bt[n], wt[n], tat[n], p[n], at[n], btcopy[n];
	printf("Enter the burst time of the processes:\n");

	for(int i = 0; i < n; ++i) {
		scanf("%d", bt+i);
		btcopy[i] = bt[i];
		p[i] = i+1;
	}

	printf("Enter the arrival time of the processes:\n");

	for(int i = 0; i < n; ++i)
		scanf("%d", at+i);

	int timeElapsed = 0, completed = 0;

	while(completed != n) {
		int min = 9999, minIndex = -1;
		for(int i = 0; i < n; ++i) 
			if(at[i] <= timeElapsed && bt[i] < min && bt[i] > 0) {
				min = bt[i];
				minIndex = i;
			}
		if(minIndex == -1) {
			timeElapsed++;
			continue;
		}
		bt[minIndex]--;
		if(bt[minIndex] == 0) {
			completed++;
			tat[minIndex] = timeElapsed + 1 - at[minIndex];
			wt[minIndex] = tat[minIndex] - btcopy[minIndex];
		}
		timeElapsed++;
	}

	float avg_wt = 0.0f, avg_tat = 0.0f;
	printf("Process \tBurst Time \tWaiting time \tTurn Around Time\n");
	for(int i = 0; i < n; ++i) {
		printf("%d\t%d\t\t%d\t\t%d\n", p[i], btcopy[i], wt[i], tat[i]);
		avg_wt += (wt[i] * 1.0 / n);
		avg_tat += (tat[i] * 1.0 / n);
	}

	printf("\nAverage Wating Time: %.2f\n", avg_wt);
	printf("Average Turn Around Time: %.2f\n", avg_tat);

	return 0;
}