// Subarray of given sum
// Problem Statement:
// Given an unsorted array of non-negative integers, find if there exists a subarray of given sum.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

// using sliding window technique
// this approach only works well with non-negative array elements
bool found(vector<int> &v, int sum){
    int n = v.size();
    int curr_sum = v[0];
    int start = 0;

    for(int end = 1; end < n; end++)
    {
        // clearing the previous window
        while(curr_sum > sum && start <= end)
            curr_sum -= v[start++];

        // check if the curr_sum equals to sum
        if(curr_sum == sum)
            return true;

        // add the next element to curr_sum
        if(end < n)
            curr_sum += v[end];
    }

    if(curr_sum == sum)
        return true;

    return false;
}
signed main(){
    eff;
    int n,sum;
    cin>>n>>sum;
    vi v(n);
    for(int i = 0; i < n; i++)
     cin>>v[i];

    cout<<found(v,sum);

    return 0;
}

// Time Complexity: O(n)  -> every element is traversed once(i.e going in the window atmost ones and going out of winddow atmost ones)
// Auxillary Space: O(1)