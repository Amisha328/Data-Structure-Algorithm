// Remove duplicates from a sorted array and return the new array and size of the new array.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int Naive_duplicate(vi &v, int n)
{
    vi temp(n);
    int res = 1;
    temp[0] = v[0];
    for(int i = 1; i < n; i++)
    {
        if(temp[res-1] != v[i])
            temp[res++] = v[i];
    }  
    for(int i = 0; i < res; i++)
        v[i] = temp[i];

    return res;
}

int Eff_duplicate(vi &v, int n)
{
    int res = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[res-1] != v[i])
            v[res++] = v[i];
    }

    return res;
}

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);

    for(int i = 0; i < n; i++)
        cin>>v[i];

    // Naive Solution
    //int size = Naive_duplicate(v, n);

    // Efficient Solution
    int size = Eff_duplicate(v, n);

    for(int i = 0; i < size; i++)
        cout<<v[i]<<" ";  

    cout<<endl;
    cout<<size<<endl;     

    return 0;
}

// Naive solution:
// Time complexity: O(n)
// Space complexity: O(n)

// Efficient Solution:
// Time complexity: O(n)
// Space complexity: O(1)