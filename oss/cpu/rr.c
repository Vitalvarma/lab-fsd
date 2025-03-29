#include <stdio.h>

int main() {
    int n, pid[10], bt[10], wt[10], tat[10], tq;
    int total_wait = 0, total_tat = 0;
    float avg_wait, avg_tat;

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid number of processes. Must be between 1 and 10.\n");
        return 1;
    }

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    int remaining_bt[10];  // Track remaining burst time
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
        wt[i] = 0;  // Initialize waiting time
    }

    int current_time = 0;
    int completed = 0;

    // Round Robin Scheduling
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > tq) {
                    current_time += tq;
                    remaining_bt[i] -= tq;
                } else {
                    current_time += remaining_bt[i];
                    tat[i] = current_time;  // TAT = Completion Time (since AT=0)
                    wt[i] = tat[i] - bt[i]; // WT = TAT - BT
                    remaining_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Calculate total waiting and turnaround time
    for (int i = 0; i < n; i++) {
        total_wait += wt[i];
        total_tat += tat[i];
    }

    // Calculate averages
    avg_wait = (float)total_wait / n;
    avg_tat = (float)total_tat / n;

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}