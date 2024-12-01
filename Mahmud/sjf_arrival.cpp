#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int pid[n], arrival[n], burst[n], waiting[n], turnaround[n];
    bool completed[n];

    // Input process details
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i];
        pid[i] = i + 1;
    }

    int completedProcesses = 0, currentTime = 0;
    while (completedProcesses < n) {
        int shortestJob = -1, minBurst = 1e9;

        // Find the shortest job among the processes that have arrived and are not completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && arrival[i] <= currentTime && burst[i] < minBurst) {
                shortestJob = i;
                minBurst = burst[i];
            }
        }

        if (shortestJob == -1) {
            // If no process has arrived yet, increment the time
            currentTime++;
        } else {
            // Process the selected job
            currentTime += burst[shortestJob];
            turnaround[shortestJob] = currentTime - arrival[shortestJob];
            waiting[shortestJob] = turnaround[shortestJob] - burst[shortestJob];
            completed[shortestJob] = true;
            completedProcesses++;
        }
    }

    // Display the results
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << waiting[i] << "\t" << turnaround[i] << endl;
    }

    // Calculate average waiting and turnaround times
    double avgWaiting = 0, avgTurnaround = 0;
    for (int i = 0; i < n; i++) {
        avgWaiting += waiting[i];
        avgTurnaround += turnaround[i];
    }

    cout << "\nAverage Waiting Time: " << avgWaiting / n;
    cout << "\nAverage Turnaround Time: " << avgTurnaround / n;

    return 0;
}
