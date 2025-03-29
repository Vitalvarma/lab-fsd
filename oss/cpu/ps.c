#include <stdio.h>

int main() {
    int n, pid[10], bt[10], priority[10], wt[10], tat[10];
    int total_wait = 0, total_tat = 0;
    float avg_wait, avg_tat;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid input. Number of processes must be 1-10.\n");
        return 1;
    }

    printf("Enter burst times and priority for each process (lower number = higher priority):\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign process IDs (1, 2, 3, ...)
        printf("Process %d (Burst Time Priority): ", pid[i]);
        scanf("%d %d", &bt[i], &priority[i]);
    }

    // Selection Sort to order processes by priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (priority[j] < priority[min_idx]) {
                min_idx = j;
            }
        }
        // Swap burst times
        int temp_bt = bt[i];
        bt[i] = bt[min_idx];
        bt[min_idx] = temp_bt;
        // Swap priorities
        int temp_p = priority[i];
        priority[i] = priority[min_idx];
        priority[min_idx] = temp_p;
        // Swap process IDs
        int temp_pid = pid[i];
        pid[i] = pid[min_idx];
        pid[min_idx] = temp_pid;
    }

    // Calculate Waiting Time (WT) and Turnaround Time (TAT)
    wt[0] = 0;          // First process has 0 waiting time
    tat[0] = bt[0];     // TAT = BT + WT (WT=0 for first process)
    total_tat = tat[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // WT = previous WT + previous BT
        total_wait += wt[i];
        tat[i] = wt[i] + bt[i];         // TAT = WT + BT
        total_tat += tat[i];
    }

    // Calculate averages
    avg_wait = (float)total_wait / n;
    avg_tat = (float)total_tat / n;

    // Print results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}