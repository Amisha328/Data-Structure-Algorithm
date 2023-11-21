// Largest Rectangle in Histogram
// Problem link:
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#


#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.

    // TC -> O(4N) | SC -> O(N)
    // Involves two pass of vector
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> leftSmaller(n);
        vector<long long> rightSmaller(n);
        stack<long long> st;
        
        // Finding the Left Smaller 
        for(auto i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            //if no Nearest Smaller to Left exist the take -1(ground)
            if(st.empty())
                leftSmaller[i] = -1;
            else
                leftSmaller[i] = st.top();
            st.push(i);
        }
        
        // empty the stack
        while(!st.empty())
            st.pop();
        
        // Finding the Right Smaller 
        for(auto i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            // if no Next Smaller to Right exist the take n(ground)
            if(st.empty())
                rightSmaller[i] = n;
            else
                rightSmaller[i] = st.top();
            st.push(i);
        }
        
        // width = (NGR-NGL)-1 
        long long maxArea = 0;
        for(auto i = 0; i < n; i++){
            maxArea = max(maxArea, arr[i] * (rightSmaller[i] - leftSmaller[i] - 1));
        }
        return maxArea;
    }

    /*
    // Do this only if asked to further optimize else don't
    
    // Involves one pass of vector
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        for(int i = 0; i <= n; i++)
        {
            while(!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                int height = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            s.push(i);
        }
        return maxArea;
    } 
    */     
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends