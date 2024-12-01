#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int tq, cnt = 0, time_elapsed = 0;
    vector<int> bt(n), at(n), wt(n), tat(n), rem_bt(n), is_completed(n, 0);
    float total_wt = 0, total_tat = 0;

    // Input burst time and arrival time
    cout << "Enter burst time and arrival time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> bt[i];
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> at[i];
        rem_bt[i] = bt[i];
    }

    cout << "Enter the time quantum: ";
    cin >> tq;

    // Sort processes based on arrival time
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, ..., n-1
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return at[i] < at[j]; // Sort by arrival time
    });

    // Process scheduling using Round Robin
    queue<int> ready_queue;
    int current_time = at[indices[0]]; // Start at the earliest arrival time
    int i = 0; // Track processes being added to the queue

    while (cnt < n) {
        // Add processes to the ready queue based on arrival time
        while (i < n && at[indices[i]] <= current_time) {
            ready_queue.push(indices[i]);
            i++;
        }

        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        int pid = ready_queue.front();
        ready_queue.pop();

        int time_spent = min(rem_bt[pid], tq);
        rem_bt[pid] -= time_spent;
        current_time += time_spent;

        // Add new processes that have arrived during execution
        while (i < n && at[indices[i]] <= current_time) {
            ready_queue.push(indices[i]);
            i++;
        }

        // If process is completed
        if (rem_bt[pid] == 0 && !is_completed[pid]) {
            cnt++;
            is_completed[pid] = 1;
            tat[pid] = current_time - at[pid];
            wt[pid] = tat[pid] - bt[pid];
            total_wt += wt[pid];
            total_tat += tat[pid];
        } else {
            // Re-add process to the queue if not completed
            ready_queue.push(pid);
        }
    }

    // Calculate average waiting time and turnaround time
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    // Print results
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << avg_wt << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << avg_tat << endl;

    return 0;
}
