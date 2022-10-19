// Sort K-Sorted Array
// Sort an array that is already k-sorted.
// The element at index i will be present between the index i-k to i+k in the sorted array.

#include<bits/stdc++.h>
using namespace std;

void kSorted(vector<int> &arr, int n, int k){
          // Min-Heap
          priority_queue<int, vector<int>, greater<int>> pq;
          for(int i = 0; i <= k; i++)
                    pq.push(arr[i]);
          int idx = 0;
          for(int i = k+1; i < n; i++){
                    arr[idx++] = pq.top();
                    pq.pop();
                    pq.push(arr[i]);
          }
          while(!pq.empty()){
                    arr[idx++] = pq.top();
                    pq.pop();
          }
}
int main()
{
          int n;
          cin>>n;
          vector<int> v(n);
          int k;
          cin>>k;
          for(int i = 0; i < n; i++)
          cin>>v[i];
          kSorted(v, n, k);
          for(auto it: v)
                    cout<<it<<" ";
          return 0;
}