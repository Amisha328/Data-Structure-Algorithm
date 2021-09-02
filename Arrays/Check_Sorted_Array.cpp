// Check if an Array is Sorted

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

bool isSorted(vi &arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1])   return false;
    }
    return true;
}
signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<< isSorted(v,n);    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)