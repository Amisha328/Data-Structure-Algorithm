// Swapping pairs make sum equal
// Problem link: https://www.geeksforgeeks.org/find-a-pair-swapping-which-makes-sum-of-two-arrays-same/


#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
// TC->O(nlogn)+O(mlogm)  | SC->O(1)
     int findSwapValues(int A[], int n, int B[], int m)
     {
        int sum1 = accumulate(A, A+n, 0LL);
        int sum2 = accumulate(B, B+m, 0LL);
        
        sort(A, A+n);
        sort(B, B+m);
        
        
        int i = 0, j = 0;
        while(i < n && j < m)
        {

          // sumA - a + b = sumB - b + a
          // 2a - 2b  = sumA - sumB
          // a - b  = (sumA - sumB) / 2
           if(sum1-A[i]+B[j] == sum2+A[i]-B[j]) 
                return 1;
           else if(sum1-A[i]+B[j] > sum2+A[i]-B[j]) 
                i++;
           else 
                j++;
        }
        
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{

    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    return 0;
}