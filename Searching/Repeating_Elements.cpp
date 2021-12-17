// Repeating Elements
// Modification of array is not allowed.

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

    // Naive solution
    // Time complexity: O(n)
    // Space complexity: O(n)
    /*
    vector<bool> vb(n-1,false);
    for(int i = 0; i < n; i++){
        if(vb[v[i]] == true)
        {
            cout<<v[i];
            break;
        }
        
        vb[v[i]] = true;
        */

       // Efficient approach
        int slow = v[0]+1, fast = v[0]+1;
        do
        {
            slow = v[slow]+1;
            fast = v[v[fast]+1]+1;
            
        } while (slow != fast);

        slow = v[0]+1;

        while(slow != fast)
        {
            slow = v[slow]+1;
            fast = v[fast]+1;
        }

        cout<<slow-1;
        return 0;
    
}

// Efficient approach
// Time complexity: O(n)
// Auxiliary Space complexity: O(1)