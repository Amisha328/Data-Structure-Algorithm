// Median from Data Stream
// Problem link:
// https://leetcode.com/problems/find-median-from-data-stream/
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> max_heap; // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> min_heap; // stores the larger half
    void insertHeap(int &x)
    {
        if(max_heap.empty() || x <= max_heap.top())
            max_heap.push(x);
        else
            min_heap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // if no of element is odd,
        // then max_heap can have one extra element then min_heap.
        // max_heap <= 1+min_heap
        
        // So, if difference between the size of max_heap and min_heap gets more than one 
        // then balancing is required
        if(max_heap.size() - min_heap.size() == 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        // if no of element is even,
        // then min_heap can have less or equal element then max_heap.
        // min_heap <= max_heap
        
        // So, if size of min_heap gets more than max_heap size
        // then balancing is required
        else if(min_heap.size() - max_heap.size() == 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        // if both heaps have equal elements the of elements is even
        // so median is the average of top of min and max heap.
        if(max_heap.size() == min_heap.size())
            return ((double)(max_heap.top()+min_heap.top())/2);
        else // odd no of elements
            return (double)max_heap.top();
    }
};


int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
} 