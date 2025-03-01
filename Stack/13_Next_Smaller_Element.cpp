// Next Smaller Element
// Problme link:
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/#
// https://www.codingninjas.com/codestudio/problem-details/next-smaller-element_1112581


#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    
    public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        // Write your code here.
        vector<int> ans(n);
        stack<int> s;
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && s.top() >= arr[i])
                s.pop();
            if(s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.nextSmallerElement(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}
