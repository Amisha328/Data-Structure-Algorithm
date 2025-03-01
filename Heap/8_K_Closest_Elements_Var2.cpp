// K Closest Elements
// Problem link:
// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1/#


#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int,int>> max_heap; // {arr[i]-x, arr[i]}
        for(auto it: arr){
            if(abs(it-x) != 0) // X is present in the array, then it need not be considered.
                // if two elements have same diff then max_heap will have max element at top 
                // but we want the min element to be at the top so that the max element remains 
                // at the bottom ans is not pop out.
                max_heap.push({abs(it-x), -1 * it});
            if(max_heap.size() > k)
                max_heap.pop();
        }
        vector<int> ans;
        while(!max_heap.empty()){
            ans.push_back(-1 * max_heap.top().second);
            max_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  

