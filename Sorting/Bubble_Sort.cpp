// In the first pass it moves the first largest element to the last index.
// In second pass it move the second largest element to the last second index and so on.

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
         
    //If at any point array becomes sorted or is sorted initially the swapped will remain false hence we can end the process.
    bool swapped = false;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }

        if(swapped == false) break;
    }

    for(int i = 0; i < n; i++)
        cout<<v[i]<<" ";
    return 0;
}


// Time Complexity: O(n^2)
// Auxiliary Space Complexity: O(1)