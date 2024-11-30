#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"number of process"<<endl;
    cin>>n;
    int pid[n],bt[n],wt[n],aat[n],t[n],tat[n];
    float s=0,twt;
    cout<<"process id"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>pid[i];
    }
    cout<<"enter brust time"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    cout<<"enter arrival time :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>aat[i];
    }

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
    cout<<"average wt time "<<s/n<<endl;

}

