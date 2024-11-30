#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], pos, temp;
    float awt = 0;

    printf("Enter burst time for each process:\n");
    for (int a = 0; a < n; a++) {
        printf("Process %d burst time: ", a + 1);
        scanf("%d", &bt[a]);
    }

   
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos]) {
                pos = j;
            }
        }
        

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

 
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }

    awt /= n;  // Calculate average waiting time

    printf("Average Waiting Time: %.2f\n", awt);

    return 0;
}
