#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];
    cout << "Enter burst time for each process:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
    }

    int wt[n];
    wt[0] = 0;

    // Calculate waiting time for each process
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    int tat[n];
    float avg_wt = 0, avg_tat = 0;

    // Calculate turnaround time and averages
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << bt[i] << "\t\t"
             << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_wt << endl;
    cout << "Average Turnaround Time: " << avg_tat << endl;

    return 0;
}
