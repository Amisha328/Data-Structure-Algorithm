// Given n ranges, find the maximum appearing element in the ranges.
// Input:
// l[] = {1, 2, 3}
// R[] = {3, 5, 7}
// O/P: 3 
// Explanation:
// range1: [1 to 3] = {1, 2, 3}
// range2: [2 to 5] = {2, 3, 4, 5}
// range3: [3 to 7] = {2, 4, 5, 6, 7}
// The maximum frequency element in the ranges is 3.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    // this method can be used when 0 <= l[i] <= r[i] <= 1000
    // using prefix sum method
    vi l(n), r(n);
    for(int i = 0; i < n; i++)
        cin>>l[i];
    for(int i = 0; i < n; i++)
        cin>>r[i];

    vi pref_sum(1000);
    for(int i = 0; i < n; i++)
    {
        // mark the beginning of the range as 1 in the prefix sum array.
        pref_sum[l[i]]++;
        // mark the end of the range as -1 in the prefix sum array such that it nullifies the increment.
        pref_sum[r[i]+1]--;
    }
    int max_freq = pref_sum[0];
    int res = 0; 
    for(int i = 1; i < 1000; i++)
    {
        pref_sum[i] += pref_sum[i-1];
        if(pref_sum[i] > max_freq)
        {
            max_freq = pref_sum[i];
            res = i;
        }
    }
    cout<<res;
    return 0;
}