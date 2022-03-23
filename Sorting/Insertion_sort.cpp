// It moves all the greater elements one place ahead and insert the new element in the right place.
// It is a stable sort.

// https://practice.geeksforgeeks.org/problems/insertion-sort/1
// https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179

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

    // It moves all the greater elements one place ahead and insert the new element.

    for(int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key) // we don’t include equal sign here to ensure stability
        {
            v[j+1] = v[j];  // shifting all greater elements to the right
                j--;
        }

        v[j+1] = key;
    }

    for(auto &i : v)
        cout<<i<<" ";
    return 0;
}
// Time Complexity in worst case is O(n^2) - when array is sorted in reverse order.
// Time Complexity in best case is O(n) - when the array is already sorted
// Time Complexity in average case is O(n^2)
// Auxiliary Space: O(1)