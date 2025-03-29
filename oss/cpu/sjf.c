#include <stdio.h>

int main() {
    int n, pid[10], bt[10], wt[10], tat[10];
    int total_wait = 0, total_tat = 0;
    float avg_wait, avg_tat;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid input. Number of processes must be 1-10.\n");
        return 1;
    }

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign process IDs (1, 2, 3, ...)
        printf("Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Selection Sort to order processes by burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[min_idx]) {
                min_idx = j;
            }
        }
        // Swap burst times
        int temp_bt = bt[i];
        bt[i] = bt[min_idx];
        bt[min_idx] = temp_bt;
        // Swap process IDs to maintain consistency
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
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}