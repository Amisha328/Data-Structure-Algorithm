// Kth element in Matrix
// Problem link:
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];

int kthSmallest(int arr[MAX][MAX], int n, int k)
{
      priority_queue<int> max_heap;
      for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
                max_heap.push(arr[i][j]);
                 // If the element is greater than the current top of heap so it can't be part of kth smallest.
                 // Since, each row is sorted in ascending order,
                 // hence, elements to the right of the same row also can't be part of kth smallest.
	       // So, we shift to next row.
                if(max_heap.top() < arr[i][j])
                {
                    i++;
                    j = 0;
                }
                if(max_heap.size() > k){
                     max_heap.pop();
                }
          }
      }
      return max_heap.top();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}


