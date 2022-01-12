// Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given value.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

int isThere(vector<int> &arr, int n, int sum, int cap)
{
    if(n < 0)
        return 0;

    if(sum == 0 && cap == 2)
        return 1;

    if(arr[n-1] > sum)
        return isThere(arr, n-1, sum, cap);

    return isThere(arr, n-1, sum-arr[n-1], cap+1) || isThere(arr, n-1, sum, cap);

}
signed main()
{
    eff;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<isThere(v,n,k,0);    
    return 0;
}