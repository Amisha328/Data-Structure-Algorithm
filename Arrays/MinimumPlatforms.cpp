// Minimum Platforms
// Problem link: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

// Program to find minimum number of platforms required on a railway station such that no train waits.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // TC-> O(nlogn) | SC->O(n)
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i = 1, j = 0;
    	int max_platform = 1;
    	int needed_platform = 0;
    	while(i < n && j < n)
    	{
              // If next train in sorted order is arrival then incremnet the number of platforms
    	    if(arr[i] <= dep[j])
    	    {
    	        i++;
    	        max_platform++;
    	    }
    	    else if(dep[j] < arr[i])
    	    {
    	        j++;
    	        max_platform--;
    	    }
    	    
    	    needed_platform = max(needed_platform,max_platform);
    	}
    	
    	return needed_platform;
    }
};
int main()
{
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
   return 0;
}  