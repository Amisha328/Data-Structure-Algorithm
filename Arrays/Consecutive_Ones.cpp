// Maximum consecutive 1s
// Problem Statement:
// Find count of maximum consecutive 1s in a binary array.


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

    int max_count = 0, count = 0;
    for(int i = 0; i < n; i++)
    {
        
        if(v[i] == 0)
            count = 0;
        else
        {
            count++;
            max_count = max(max_count, count);
        }    
    }

    cout<<max_count;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)