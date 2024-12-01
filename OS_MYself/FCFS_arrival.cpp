#include<bits/stdc++.h>
using namespace std;


void CalculateWaitingTime(int at[],int bt[], int N)
{

    
    int wt[N];
    wt[0] = 0;


    
    cout << "PN\t\tAT\t\t"<< "BT\t\tWT\n\n";
    cout << "1"<< "\t\t" << at[0] << "\t\t"<< bt[0] << "\t\t" << wt[0] << endl;

    
    for (int i = 1; i < 5; i++) {
        wt[i] = (at[i - 1] + bt[i - 1]+ wt[i - 1]) - at[i];

        // Print the waiting time for
        // each process
        cout << i + 1 << "\t\t" << at[i]
             << "\t\t" << bt[i] << "\t\t"
             << wt[i] << endl;
    }

    // Declare variable to calculate
    // average
    float average;
    float sum = 0;

    // Loop to calculate sum of all
    // waiting time
    for (int i = 0; i < 5; i++) {
        sum = sum + wt[i];
    }

    // Find average waiting time
    // by dividing it by no. of process
    average = sum / 5;

    // Print Average Waiting Time
    cout << "\nAverage waiting time = "
         << average;
}


int main()
{
    int n;cout<<"number of process"<<endl;cin>>n;

    int bt[n],wt[n],aat[n],t[n],tat[n];
    float s=0,twt;

    cout<<"enter brust time"<<endl;
    for(int i=0;i<n;i++) cin>>bt[i]; /// input burst time

    cout<<"enter arrival time :"<<endl;
    for(int i=0;i<n;i++) cin>>aat[i]; /// input arrival time

    t[0]=0;

    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;

        t[i+1]=t[i]+bt[i];
        wt[i]=t[i]-aat[i];
        tat[i]=wt[i]+bt[i];

        s+=wt[i];
    }
    cout<<"waiting time: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<wt[i]<<endl;
    }
    cout<<"turn around time: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<tat[i]<<endl;
    }
    cout<<"average wt time "<<s/float(n)<<endl;
}

