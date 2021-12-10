#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int pos(vi v,int l, int h, int x)
{
    if(l>h)
        return -1;

    int mid = (l+h)/2;
    if(v[mid]==x)
        return mid;
    else if(v[mid]>x)
        return pos(v,l,mid-1,x);
    else
        return pos(v,mid+1,h,x);
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
    cout<< pos(v,0,n-1,x);
    return 0;
}

// Time Complexity: 
// O(log(n)) for successful seach and theta(log(n)) for unsuccessful search.
// Auxiliary Space: O(log(n))