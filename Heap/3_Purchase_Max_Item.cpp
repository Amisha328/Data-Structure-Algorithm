// Buy Maximum Items with Given Sum

#include<bits/stdc++.h>
using namespace std;

int maxItems(vector<int> &arr, int n, int sum){
          priority_queue<int, vector<int>, greater<int>> pq;
          for(auto it: arr)
                    pq.push(it);
          int res = 0;
          while(true){
                    sum -= pq.top();
                    pq.pop();
                    if(sum >= 0) res++;
                    else return res;
          }
          return res;
}
int main()
{
          int n;
          cin>>n;
          vector<int> v(n);
          for(int i = 0; i < n; i++)  cin>>v[i];
          int sum;
          cin>>sum;
          cout<<maxItems(v, n, sum);         
          return 0;
}