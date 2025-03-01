// Stock Span Problem
// Problem link:
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/#
// https://www.codingninjas.com/codestudio/problem-details/stock-span_99652
// https://leetcode.com/problems/online-stock-span/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    /*
    // Using pair in stack
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans(n);
       stack<pair<int, int>> s; // ele, idx
       for(int i = 0; i < n; i++)
       {
           while(!s.empty() && s.top().first <= price[i])
                s.pop();
            if(s.empty())
                ans[i] = i-(-1);
            else
                ans[i] = i-s.top().second;
            
            s.push({price[i], i});
       }
       return ans;
    }
    */
   // Using index only in stack
   vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n);
       stack<int> s;
       for(int i = 0; i < n; i++)
       {
           while(!s.empty() && price[s.top()] <= price[i])
                s.pop();
            if(s.empty())
                ans[i] = i-(-1);
            else
                ans[i] = i-s.top();
            
            s.push(i);
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
		int i,a[n];
		for(i=0;i<n;i++)
		          cin>>a[i];
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}