// Merge K Sorted Arrays
// Problem link:
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/#
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0\

#include<bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
        for(int i = 0; i < K; i++){
            min_heap.push({arr[i][0], {i, 0}});
        }
        vector<int> res;
        while(!min_heap.empty()){
            res.emplace_back(min_heap.top().first);
            int r = min_heap.top().second.first;
            int c = min_heap.top().second.second;
            min_heap.pop();
            if(c+1 < K) //  if(c+1 < arr[r].size()) if elements in each row is differnt
                min_heap.push({arr[r][c+1], {r, c+1}});
        }
        return res;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
