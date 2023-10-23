#include<bits/stdc++.h>
using namespace std;

int main(){
          int n, k;
          cin>>n;
          vector<long long> cost(n);
          for(int i = 0; i < n; i++) cin>>cost[i];
          cin>>k;
          vector<long long> clockwiseSum(n), anticlockSum(n);
          clockwiseSum[0] = cost[0];
          anticlockSum[n-1] = cost[0];

          for(int i = 1; i < n; i++)
             clockwiseSum[i] = clockwiseSum[i-1] + cost[i];
          for(int i = n-2; i >= 0; i--)
             anticlockSum[i] = anticlockSum[i+1] + cost[i+1];

          // for(int i = 0; i < n; i++){
          //       cout<<clockwiseSum[i]<<" ";
          // }
          // cout<<endl;
          // for(int i = 0; i < n; i++){
          //       cout<<anticlockSum[i]<<" ";
          // }
          // cout<<endl;
          int curr_pos = 0;
          while(k--){
             int dir;
             long long dis;
             cin>>dir>>dis;
             int new_pos;
             long long totalcost = 0;
             if(dir == -1)
                new_pos = (((curr_pos - dis) % n) + n) % n;
             else
              new_pos = (curr_pos + dis)%n;
              // cout<<"curr pos = "<<curr_pos<<" new pos = "<<new_pos<<endl;
             if(curr_pos == 0 && new_pos == n-1 || curr_pos == n-1 && new_pos == 0)
                    totalcost = cost[0];
             else{
             if(new_pos < curr_pos)       
             totalcost = min(abs(clockwiseSum[new_pos] - clockwiseSum[curr_pos]), abs(anticlockSum[0] - anticlockSum[new_pos] + anticlockSum[curr_pos])); 
             else
             totalcost = min(abs(clockwiseSum[new_pos] - clockwiseSum[curr_pos]), abs(anticlockSum[0] - anticlockSum[curr_pos] + anticlockSum[new_pos]));      
             }
             curr_pos = new_pos;
             cout<<totalcost<<endl;
          }
          return 0;

}