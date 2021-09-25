// Maximum Circular Sum Subarray
// The task is to find maximum circular sum subarray of a given array. 

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    int max_val = v[0], max_sum = v[0];
    int min_val = v[0], min_sum = v[0];
    // Kadane's Algorithm
    for(int i = 1; i < n; i++)
    {
        // Max sum subarray in noraml array
        max_sum = max(max_sum + v[i], v[i]);
        max_val = max(max_val, max_sum);

        // Min sum subarray in noraml array
        min_sum = min(min_sum + v[i], v[i]); 
        min_val = min(min_val, min_sum);

    }
   // cout<<max_val<<endl;
    if(max_val < 0)
        cout<<max_val;
    else
    {
    // Max sum subarray in circular array can be calculated by subtracting min sum of array from sum of array.
     int sum = accumulate(v.begin(), v.end(),0);
     int cir_max = min_val = sum - min_val;
     // find max of normal sum subarray and max sum subarray in circular array
    cout<<max(max_val, cir_max);
    }

    return 0;
}

// Time complexity : O(n)
// Space complexity: O(1)