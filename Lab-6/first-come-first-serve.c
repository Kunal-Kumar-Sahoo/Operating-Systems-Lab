// Write a program to simulate the working of `First come first serve` scheduling algorithm.

#include <stdio.h>
#include <stdbool.h>

typedef struct process {
	int process_id;
	int arrival_time;
	int burst_time;
} process;

void swap(process *p1, process *p2) {
	process temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void sort_processes(process processes[], int n) {
	bool swapped;
	for(int i = 0; i < n-1; ++i) {
		swapped = false;
		for(int j = 0; j < n-i-1; ++j) 
			if(processes[j].arrival_time > processes[j+1].arrival_time) {
				swap(processes+j, processes+j+1);
				swapped = true;
			}
		if(!swapped) break;
	}
}

float mean(int arr[], int n) {
	float mean_ = arr[0] * 1.0;
	for(int i = 1; i < n; ++i)
		mean_ += (1.0 * arr[i]);
	return mean_ / n;
}

int main() {
	printf("Enter total number of processes: ");
	int n; scanf("%d", &n);

	process processes[n];

	for(int i = 0; i < n; ++i) {
		printf("Enter arrival time and burst time of process number %d: ", i);
		processes[i].process_id = i;
		scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
	}

	sort_processes(processes, n);

	int completion_time[n], turn_around_time[n], waiting_time[n];

	// Driver logic
	for(int count = 0, current_time = 0; count < n; ++count) {
		if(processes[count].arrival_time <= current_time) {
			current_time += processes[count].burst_time;
			completion_time[count] = current_time;
			turn_around_time[count] = current_time - processes[count].arrival_time;
			waiting_time[count] = turn_around_time[count] - processes[count].burst_time;
		}
		else {
			count--;
			current_time++;
		}
	}

	printf("Average turn around time: %f\n", mean(turn_around_time, n));
	printf("Average waiting time: %f\n", mean(waiting_time, n));
	
	return 0;
}

