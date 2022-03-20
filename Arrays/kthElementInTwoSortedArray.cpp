// K-th Element of Two Sorted Arrays
// problem link:https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // TC->O(k) | SC->O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int c = 0;
       int i = 0, j = 0;
       while(i < n && j < m)
       {
                 if(arr1[i] < arr2[j])
                 {
                           c++;
                           if(c == k)
                              return arr1[i];
                           i++;
                 }
                 else{
                    c++;
                    if(c == k)
                      return arr2[j];
                    j++;
                 }
       }
       while(i < n)
       {
           c++;
          if(c == k)
             return arr1[i];
          i++;      
       }
       while(j < n)
       {
          c++;
          if(c == k)
             return arr2[j];
          j++;
       }
       return 1;
    }
};

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int arr1[n],arr2[m];
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<m;i++)
		cin>>arr2[i];
		
	Solution ob;
          cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
          return 0;
}  