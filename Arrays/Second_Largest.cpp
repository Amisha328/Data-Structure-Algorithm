#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

signed main(){
    eff;
    int f = INT_MIN,s = INT_MIN;
     
     int n;
     cin>>n;
    vi v(n); 
    for(int i = 0; i < n; i++)
        cin>>v[i];

    for(int i = 0; i < n; i++)
    {
        if(v[i] > f)
        {
          s = f;
          f = v[i];
        }  
        // handle the case when all then elements in array are negative
        else if (v[i] < f) {
            if (s == -1 || s < v[i])
                s = v[i];
        }
        // if array contails contails the duplicate elements
        else if(s == INT_MIN)
            s = -1;
    }
    cout<<s;  
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)