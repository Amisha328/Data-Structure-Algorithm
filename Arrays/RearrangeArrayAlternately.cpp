// Rearrange Array Alternately 
// Problem link: https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // TC-> O(n) | SC->O(1)
    void rearrange(long long *arr, int n) 
    { 
    	int min = 0, max = n-1;
    	int max_element = arr[n-1]+1;
    	
    	for(int i = 0; i < n; i++)
    	{
    	    if(i%2 == 0)
    	    {
    	        arr[i] += (arr[max] % max_element) * max_element;
    	        max--;
    	    }
    	    else
    	    {
    	         arr[i] += (arr[min] % max_element) * max_element;
    	         min++;
    	    }
    	}
    	for(int i = 0; i < n; i++)
    	    arr[i] = arr[i]/max_element;
    }
};

int main() 
{
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        ob.rearrange(arr, n);
        for (int i = 0; i < n; i++) 
	cout << arr[i] << " ";
		
        cout << endl;
        return 0; 
} 
