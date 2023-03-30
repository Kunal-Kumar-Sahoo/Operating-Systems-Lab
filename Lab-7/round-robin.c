#include <stdio.h>

int main() {
	int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
	float avg_wt = 0.0f, avg_tat = 0.0f;

	printf("Enter total number of processes: ");
	scanf("%d", &n);

	y = n;

	for(i = 0; i < n; ++i) {
		printf("Enter the Arrival and Burst time of the Process[%d]: ", i+1);
		scanf("%d %d", at+i, bt+i);
		temp[i] = bt[i];
	}

	printf("Enter time quantum for the algorithm: ");
	scanf("%d", &quant);

	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
	for(sum = 0, i = 0; y != 0; ) {
		if(temp[i] <= quant && temp[i] > 0) {
			sum += temp[i];
			temp[i] = 0;
			count = 1;
		}
		else if(temp[i] > 0) {
			temp[i] -= quant;
			sum += quant;
		}

		if(temp[i] == 0 && count == 1) {
			y--;
			printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
			wt = wt+sum-at[i]-bt[i];
			tat = tat+sum-at[i];
			count = 0;
		}

		if(i == n-1)
			i = 0;
		else if(at[i+1] <= sum) 
			i++;
		else i = 0;
	}

	avg_wt = wt * 1.0 / n;
	avg_tat = tat * 1.0 / n;

	printf("\nAverage Turn Around Time: \t%f", avg_wt);
	printf("\nAverage Waiting Time: \t%f\n", avg_tat);
	
	return 0;
}