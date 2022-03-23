// Does less memory writes compared to QuickSort, Merge Sort, InsertionSort, however it is not the optimal.
// It is not stable i.e the order of equal elements may change during sorting.
// Requires no extra memory for sorting.

// https://www.codingninjas.com/codestudio/problem-details/selection-sort_981162

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

// In-place implementation of selection sort
signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    // Approach:
    // We find the min element and put it on the first position.
    // We find the next min element and place it on the second position.
    // Then we find out the third and so on.

    for(int i = 0; i < n-1; i++)
    {
        int idx = i;
        for(int j = i+1; j < n; j++)
        {
            if(v[j] < v[idx])
                 idx = j;
        }
        swap(v[i], v[idx]);
    }

    for(auto & it: v)
        cout<<it<<" ";

    return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)