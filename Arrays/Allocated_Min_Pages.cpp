// Allocate minimum number of pages

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int sum(vector<int> &v,int b, int e){
    int s=0;
    for(int i=b;i<=e;i++)
        s+=v[i];
    return s;
}

int minPages(vi v, int n, int k)
{
    // is there is only one person he reads all the books
    if(k == 1)
        return sum(v,0,n);
    // if there is only one book
    if(n == 1)
        return v[0];
    int res = INT_MAX;
    // if there are more than one book and person
    for(int i = 1; i < n; i++)
    {
        // divide the pages into two parts at i and calculate sum of pages from i+1 to n-1
        // and recursively call for k-1
        res = min(res, max(minPages(v,i,k-1), sum(v,i+1,n-1)));
    }
    return res;
}


signed main(){
    eff;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i = 0; i < n; i++)
            cin>>v[i];

    cout<<minPages(v,n,k);
    
    return 0;
}

// Naive solution with exponential time complexity