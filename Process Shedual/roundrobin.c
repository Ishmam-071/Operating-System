#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int tq, cnt = 0, time_elapsed = 0;
    int bt[n], wt[n], rem_bt[n], tat[n];
    float total_wt = 0, total_tat = 0;

  
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; 
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

  
    while (cnt < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) { 
                int time_spent = (rem_bt[i] > tq) ? tq : rem_bt[i];
                rem_bt[i] -= time_spent;
                time_elapsed += time_spent;

                
                if (rem_bt[i] == 0) {
                    cnt++; 
                    tat[i] = time_elapsed;  
                    wt[i] = tat[i] - bt[i];  
                    total_wt += wt[i];
                    total_tat += tat[i];
                }
            }
        }
    }

   
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
