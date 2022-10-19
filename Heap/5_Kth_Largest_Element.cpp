// Kth Largest Element 
// Problem link: 
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
        // Min-Heap
        // TC-> O(NlogK)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto x: nums){
            min_heap.push(x);
            if(min_heap.size() > k)
                min_heap.pop();
        }
        return min_heap.top();
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
          cout<<obj.findKthLargest(v, k);
          return 0;
}