// K largest elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> KLargest(vector<int>& nums, int k) {
        // Min-Heap
        // TC-> O(NlogK)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto x: nums){
            min_heap.push(x);
            if(min_heap.size() > k)
                min_heap.pop();
        }
        vector<int> ans;
        while(!min_heap.empty()){
                  ans.push_back(min_heap.top());
                  min_heap.pop();
        }
        return ans;
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
          vector<int> ans = obj.KLargest(v, k);
          for(auto x: ans)
                    cout<<x<<" ";
          return 0;
}