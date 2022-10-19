// Minimum Cost of ropes
// Problem link:
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
// https://www.codingninjas.com/codestudio/problems/connect-n-ropes-with-minimum-cost_630476?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Min-Heap
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        for(auto i = 0; i < n; i++){
            min_heap.push(arr[i]);
        }
        
        long long Tcost = 0;
        while(min_heap.size() >= 2){
            long long x = min_heap.top();
            min_heap.pop();
            long long y = min_heap.top();
            min_heap.pop();
            Tcost += (x+y);
            min_heap.push(x+y);
        }
        
        return Tcost;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
