
// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.


#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int end;
};

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool compare(Activity a, Activity b)
    {
        if(a.end < b.end) return 1;
        else if(a.end > b.end) return 0;
        else if(a.start < b.start) return 1;
        else return 0;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        Activity arr[n];
        
        for(int i = 0; i < n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr, arr+n, compare);
        
        int count = 1;
        int j = 0;
        for(int i = 1; i < n && j < n; i++)
        {
            if(arr[i].start > arr[j].end)
            {
                count++;
                j = i;
            }
        }
        
        return count;
        
    }
};

// { Driver Code Starts.
int main()
{
//     int t;
    
//     //testcases
//     cin >> t;
//     while(t--)
//     {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
   // }
    return 0;
}

// Expected Time Complexity : O(N * Log(N))
// Expected Auxilliary Space : O(N)
