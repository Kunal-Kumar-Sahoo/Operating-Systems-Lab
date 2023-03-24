// Write a program to simulate the working of `Shortest job first` scheduling algorithm.

#include <stdio.h>
#include <stdbool.h>

typedef struct process {
	int process_id;
	int arrival_time;
	int burst_time;
	bool completed;
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
			if(processes[j].burst_time > processes[j+1].burst_time) {
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

int find_shortest_job_index(process processes[], int n, int current_time) {
	for(int i = 0; i < n; ++i) 
		if(!processes[i].completed && processes[i].arrival_time <= current_time)
			return i;
	return -1;
}

int main() {
	printf("Enter total number of processes: ");
	int n; scanf("%d", &n);

	process processes[n];

	for(int i = 0; i < n; ++i) {
		printf("Enter arrival time and burst time of process number %d: ", i);
		processes[i].process_id = i;
		scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
		processes[i].completed = false;
	}

	sort_processes(processes, n);

	int completion_time[n], turn_around_time[n], waiting_time[n];

	for(int count = 0, current_time = 0; count < n; ++count) {
		int shortest_process_index = find_shortest_job_index(processes, n, current_time);
		if(shortest_process_index == -1) {
			count--;
			current_time++;
		}
		else {
			current_time += processes[shortest_process_index].burst_time;
			completion_time[shortest_process_index] = current_time;
			turn_around_time[shortest_process_index] = completion_time[shortest_process_index] - processes[shortest_process_index].arrival_time;
			waiting_time[shortest_process_index] = turn_around_time[shortest_process_index] - processes[shortest_process_index].burst_time;
			processes[shortest_process_index].completed = true;
		}
	}

	printf("Average turn around time: %f\n", mean(turn_around_time, n));
	printf("Average waiting time: %f\n", mean(waiting_time, n));
	
	return 0;
}