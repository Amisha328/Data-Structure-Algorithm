//  Merge Sort
// https://www.codingninjas.com/codestudio/problems/merge-sort_920442?leftPanelTab=3
// https://practice.geeksforgeeks.org/problems/merge-sort/1


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

// Divide and conquer algorithm - it first divides the array into two parts sort the individual parts and then combine them.

void merge(int arr[], int l, int m, int r)
{
         // Your code here
         int n1 = m-l+1, n2 = r-m;
         int left[n1], right[n2];
         for(int i = 0; i < n1; i++)
            left[i] = arr[l+i];
         for(int i = 0; i < n2; i++)
            right[i] = arr[m+i+1];
        
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2)
        {
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
        while(i < n1)
        {
            arr[k++] = left[i++];
        }
        while(j < n2)
        {
            arr[k++] = right[j++];
        }
}

void mergeSort(int arr[], int l, int r)
{
        //code here
        if(l >= r)
            return;
            
            int m = (l+r)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
}

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    mergeSort(v, 0, n-1);

    for(auto &it: v)
        cout<<it<<" ";
    return 0;
}

// Time Complexity: theta(n*logn)
// Auxiliary Space: theta(n)
