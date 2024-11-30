#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], pos, temp, pr[n];
    float awt = 0;

    printf("Enter burst time and priority for each process:\n");
    for (int a = 0; a < n; a++)
    {
        printf("Process %d burst time: ", a + 1);
        scanf("%d", &bt[a]);
        printf("Process %d priority: ", a + 1);
        scanf("%d", &pr[a]);
    }


    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }


        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;


        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    wt[0] = 0;


    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }

    awt /= n;

    printf("Average Waiting Time: %.2f\n", awt);

    return 0;
}