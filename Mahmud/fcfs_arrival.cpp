#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n], pid[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; // Process ID
        cout << "Enter Arrival Time and Burst Time for Process " << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    // Sort processes by Arrival Time

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    // Calculate Completion Time (CT)
    ct[0] = at[0] + bt[0]; // First process
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i]; // CPU idle
        } else {
            ct[i] = ct[i - 1] + bt[i]; // Start immediately after previous
        }
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}
