// Kth Smallest Element

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findKthSmallest(vector<int>& nums, int k) {
        // Max-Heap
        // TC-> O(NlogK)
        priority_queue<int> max_heap;
        for(auto x: nums){
            max_heap.push(x);
            if(max_heap.size() > k)
                max_heap.pop();
        }
        return max_heap.top();
    }
};

int main()
{
          int n;
          cin>>n;
          vector<int> v(n);
          int k;
          cin>>k;
          for(int i = 0; i < n; i++)
          cin>>v[i];
          Solution obj;
          cout<<obj.findKthSmallest(v, k);
          return 0;
}