// Count Occurrences in Sorted
// Given a sorted array and an element x, we need to count occurrences of x in the array.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int firstPos(vi v, int x, int n)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid] == x)
        {
            if(mid == 0 || v[mid-1] != x)
                return mid;
            else       
                r = mid - 1;
        }
        else if(v[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int lastPos(vi v, int x, int n)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid] == x)
        {
            if(mid == n-1 || v[mid+1] != x)
                return mid;
            else       
                l = mid + 1;
        }
        else if(v[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
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

     int f = firstPos(v, x, n);
     if(f == -1)
        cout<<"0";
    else
        cout<<lastPos(v, x , n) - f+1;

    return 0;
}

// Time Complexity: O(log(n))
// Auxiliary Space: O(1)