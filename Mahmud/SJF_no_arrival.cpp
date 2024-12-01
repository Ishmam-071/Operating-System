#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "number of process" << endl;
    cin >> n;
    int pid[n], bt[n], wt[n], s = 0;
    float tat, twt;

    cout << "process id" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> pid[i];
    }

    cout << "enter burst time" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }

    sort(bt, bt+n);

    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
        s += wt[i];
    }

    cout << "waiting time: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << wt[i] << endl;
    }

    cout << "turn around time: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << bt[i] + wt[i] << endl;
    }

    cout << "average wt time " << s/n << endl;

    return 0;
}
