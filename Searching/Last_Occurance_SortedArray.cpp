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
    int x;
    cin>>x;

    int l = 0, h = n-1;
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(v[mid] == x)
        {
            if(mid == n-1 || v[mid+1] != x)
                break;
            else
                l = mid+1;
        }
        else if(v[mid] > x)
            h = mid-1;
        else
            l = mid+1;
    }

    cout<<mid;
    return 0;
}

// Time Complexity: 
// O(log(n)) for successful seach and theta(log(n)) for unsuccessful search.
// Auxiliary Space: O(log(n))