// Trapping Rain Water
// Problem Statement:
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

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

    int ans = 0;

    // Approach : 1
   /* vector<int> left(n);
    vector<int> right(n);
    left[0] = v[0];
    for(int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], v[i]);
    }    

    right[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1], v[i]);
    }

    for(int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - v[i];
    }

    cout<<ans;*/

    // Approach : 2 -> Two pointer approach
    int left = 0, right = n-1;
    int l_max = v[0], r_max = 0;
    int water = 0;
    while(left < right)
    {
        if(v[left] < v[right])
        {
            (v[left] > l_max) ? l_max = v[left] : water+=(l_max-v[left]);
            left++;
        }
        else
        {
            (v[right] > r_max) ? r_max = v[right] : water+=(r_max-v[right]);
            right--;
        }
    }   

    cout<<water; 
    return 0;
}


// Approach : 1
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach : 2
// Time Complexity: O(n)
// Space Complexity: O(1)