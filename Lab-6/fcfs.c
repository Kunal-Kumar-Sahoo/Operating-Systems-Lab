#include <stdio.h>

int main() {
    printf("Enter the number of processes: ");
    int n; scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];
    float avg_wt = 0.0f, avg_tat = 0.0f;

    for(int i = 0; i < n; ++i) {
        printf("Enter process ID for process[%d]: ", i);
        scanf("%d", pid+i);
    }

    for(int i = 0; i < n; ++i) {
        printf("Enter burst time for process[%d]: ", i);
        scanf("%d", bt+i);
    }

    wt[0] = 0;
    for(int i = 1; i < n; ++i) 
        wt[i] = wt[i-1] + bt[i-1];
    
    for(int i = 0; i < n; ++i)
        tat[i] = wt[i] + bt[i];

    printf("Pid\t| Arrival Time\t| Burst Time\t| Waiting Time\t| Turn around Time\n");
    printf("-----------------------------------------------------------------------------\n");

    for(int i=0;i<n;i++)
        printf("%d\t| 0\t\t| %d\t\t| %d\t\t| %d\t\n",pid[i],bt[i],wt[i],tat[i]);

    for(int i=0;i<n;i++ ) {
        avg_wt += (wt[i]*1.0 / n);
        avg_tat += (tat[i]*1.0 / n);
    }

    printf("Average Waiting time: %f\n",avg_wt);
    printf("Average Turn around time time: %f\n",avg_tat);

    return 0;
}
