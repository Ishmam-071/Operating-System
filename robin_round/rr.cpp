#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    vector<int>bt(n);
    vector<int>wt(n);
    vector<int>rem_bt(n);
    vector<int> tat(n);
    int tq,temp1,temp2; // time quantum 
    int cnt = 0;
    for(int i=0;i<n;i++) 
    {
        cin>>bt[i];
        rem_bt[i] = bt[i];
    }
    // scan time quantum 
    cin>>tq;
    while (true){
        for(int i=0,cnt=0;i<n;i++)
            {   
                temp1 = tq;
                if (rem_bt[i]==0) {
                    cnt  = cnt+1;
                    continue;
                }
                else if(rem_bt[i]>tq)
                {
                    rem_bt[i] = rem_bt[i] - tq;
                }
                else if(rem_bt[i]>=0)
                {
                    temp1 = rem_bt[i];
                    rem_bt[i] = 0;
                }
                temp2 = temp2 + temp1;
                tat[i]


            }

    }
    
    
    return 0;
}

