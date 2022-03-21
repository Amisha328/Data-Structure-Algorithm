// Allocate Minimum number of pages
// Minimum the maximum number of pages allocated
// Only contiguous pages can be allocated
// Problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

bool isFeasible(vi &v, int n, int k, int mid)
{
    int req = 1, sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > mid) return false;
        else if(sum+v[i] > mid)
        {
            req++;
            sum = v[i];
        }
        else
            sum+=v[i];
    }

    return (req <= k);
}
int minPages(vi &v, int n, int k)
{
    int sum = 0, mx = 0;
    for(int i = 0; i < n; i++)
    {
        sum += v[i];
        mx = min(mx, v[i]);
    }

    int low = mx, high = sum, res = 0;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(isFeasible(v, n, k, mid))
        {
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return res;
}
signed main(){
    eff;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    
    cout<<minPages(v, n, k);
    

    return 0;
}
// Time complexity: O(nlog(sum))
// Auxiliary space: O(1)
