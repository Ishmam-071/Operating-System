#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;
    vector<int> bt(n),wt(n),pri(n);
    
    int pos,temp;

    float awt = 0;
    

    for(int i=0;i<n;i++) cin>>bt[i];
    
    for(int i=0;i<n;i++) cin>>pri[i];

    sort(bt.begin(),bt.end(),greater<int>());
    sort(pri.begin(),pri.end());
    wt[0] = 0;
    int sum = 0;

    for (int i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        awt = awt + wt[i];
        
    }
    cout<<"Average Waiting time : "<<awt/n<<endl;


    
    cout<<"Process ID"<<"  "<<"Burst Time"<<"  "<<"waiting time"<<"  "<<"Priority"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"  "<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t"<<pri[i]<<endl;
    }


    
}

