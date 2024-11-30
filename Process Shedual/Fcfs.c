#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n];
    float awt = 0;

    printf("Enter burst time for each process:\n");
    for (int a = 0; a < n; a++) {
        printf("Process %d burst time: ", a + 1);
        scanf("%d", &bt[a]);
    }

    wt[0] = 0;


    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }

    awt /= n; 

    printf("Average Waiting Time: %.2f\n", awt);

    return 0;
}
