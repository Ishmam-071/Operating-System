#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n; int m;
    cout<<"Enter the number of processes: \n";
    cin>>n;
    cout<<"Enter the number of resources: \n";
    cin>>m;

   int alloc[n][m];
   int max[n][m];
   int avail[m];
   int need[n][m];

   // take allocation matrix
   cout<<"Enter the allocation matrix: \n";
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>alloc[i][j];
    }
   }

   // take max matrix
   cout<<"Enter the max matrix: \n";
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>max[i][j];
    }
   }

   // take available resource matrix
   cout<<"Enter the available resource matrix: \n";
   for(int i=0; i<m; i++){
    cin>>avail[i];
   }

   // calculate need matrix
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        need[i][j] = max[i][j] - alloc[i][j];
    }
   }

   // will do the safety algorithm here
   int finish[n];
   fill(finish, finish+n, 0);

   int safeSequence[n];
   int cnt = 0;
   int avi2[m];

   for(int i=0; i<m; i++){
    avi2[i] = avail[i];
   }

   // check all the processes
   for(int k=0; k<n; k++){
    // checked unfinished process
    for (int i = 0; i < n; i++)
    {
        if(finish[i] == 0){
            int flag = 0;

            for(int j=0; j<m; j++){
                if(need[i][j] > avi2[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                for(int a=0; a<m; a++){
                    avi2[a] += alloc[i][a];
                }
                safeSequence[cnt++] = i;
                finish[i] = 1;
            }
        }
    }


   }

   // print the need matrix
   cout<<"The need matrix is: \n";
   for(int i=0; i<n; i++){
    cout<<"P "<<i<<" ";
    for(int j=0; j<m; j++){
        cout<<need[i][j]<<" ";
    }
    cout<<endl;
   }

   // print the safe sequence
   cout<<"The safe sequence is: \n";
   for(int i=0; i<n; i++){
    cout<<"P "<<safeSequence[i]<<" ";
   }
   cout<<endl;
    return 0;
}
