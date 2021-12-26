// Search in Infinite Sized Array where size of array may be in millions.
// Its is generally known as Unbounded binaray Search

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int NaiveSearch(vi arr, int x)
{
    int i = 0;
    while(true)
    {
        if(arr[i] == x) return i;
        if(arr[i] > x) return -1;
        i++;
    }
    return i;
}

int findPos(vi &v, int l, int r, int k)
{
    int n = v.size();
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid] == k)
            return mid;
        else if(v[mid] < k)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int Eff_BinaraySearch(vi arr, int x)
{
    if(arr[0] == x) return 0;
    int l = 1;
    while(true)
    {
        if(arr[l] == x) return l;
        if(arr[l] < x)
           l = l*2;
        else
          return findPos(arr,(l/2)+1, l-1, x);
    }
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
    cout<<NaiveSearch(v, x)<<endl;
    cout<<Eff_BinaraySearch(v, x);
    return 0;
}

// Naive Search
// Time Complexity: O(position of x)
// Auxiliary Space: O(1)

// Binary Search
// Time Complexity: O(log(position of x))
// Auxiliary Space: O(1)