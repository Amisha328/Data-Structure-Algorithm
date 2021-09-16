// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array 
// such that nums[i] == nums[j] and abs(i - j) <= k

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

bool containsDuplicate(vi v,int n, int k)
{
    map<int,int> m;
    // if size of k equal to array size store all the elements in the map
        if(n <= k)
        {
            for(int i = 0; i < n; i++)
            {
                // update the count of the element in the map
                m[v[i]]++;
                // if count of the element is greater than 1 return true
                if(m[v[i]] > 1)
                    return true;
            }
        }
        
        else
        {
            for(int i = 0; i <= k; i++)
            {
                m[v[i]]++;
                if(m[v[i]] > 1)
                    return true;
            }
            int j = 0;
            for(int i = k+1; i < n; i++)
            {
                m[v[j]]--;
                m[v[i]]++;
                if(m[v[i]] > 1)
                    return  true;
                j++;
            }
        }
        
        return false;
}
signed main(){
    eff;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    if(containsDuplicate(v,n,k))
        cout<<"true";
    else    
        cout<<"false";
        
    return 0;
}