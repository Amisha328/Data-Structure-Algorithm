// Sum of All Odd Length Subarrays

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    vector<int> v(n);
    v[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            v[i] = v[i-1] + arr[i];
        }
        
        int sum = v[n-1];
        if(arr.size()%2 != 0)
            sum += v[n-1];

        int k = 3;
        for(int i = 0; i < n; i++)
        {
            if(k < n)
            {
                
            }
        }
    
    return 0;
}