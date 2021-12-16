#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>


int pos(vi &v, int x, int l, int r)
{
    if(l>r)
        return -1;

    int mid = (l+r)/2;
    if(v[mid]==x)
    {
        if(mid == 0 || v[mid-1] != x)
            return mid;
        else
            return pos(v,x,l,mid-1);
    }
    else if(v[mid]>x)
        return pos(v,x,l,mid-1);
    else
        return pos(v,x,mid+1,r);
}

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    int x;
    cin>>x;

    cout<<pos(v, x, 0, n-1);
    return 0;
}

// Time Complexity: 
// O(log(n)) for successful seach and theta(log(n)) for unsuccessful search.
// Auxiliary Space: O(log(n))