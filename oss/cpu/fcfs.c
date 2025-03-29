#include <stdio.h>

int main() {
    int n, pid[10], bt[10], wt[10], tat[10];
    int totalW = 0, totalT = 0;
    float wait, turn;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid number of processes. Must be between 1 and 10.\n");
        return 1;
    }

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("%d th process: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // FCFS Scheduling Logic (Non-Preemptive)
    wt[0] = 0;          // First process has 0 waiting time
    tat[0] = bt[0];     // TAT = WT + BT (since arrival time = 0)
    totalT += tat[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];  // WT = previous WT + previous BT
        totalW += wt[i];
        tat[i] = wt[i] + bt[i];     // TAT = WT + BT
        totalT += tat[i];
    }

    // Calculate averages
    wait = (float)totalW / n;
    turn = (float)totalT / n;

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", wait);
    printf("Average Turnaround Time: %.2f\n", turn);

    return 0;
}