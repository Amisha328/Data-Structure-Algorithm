// Daily Temperatures
// Problem link:
// https://leetcode.com/problems/daily-temperatures/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        // Next Greater Element to Right 
        int n = arr.size();
        vector<int> ans(n, 0);

        stack<int> s;
        for(int i = n-1; i >= 0; i--)
        {
            // pop until we find next greater element to the right or stack gets empty
            while(!s.empty() && arr[s.top()] <= arr[i])
                s.pop();
            
            // if stack not empty, we take distance between next greater and current temperature.
            if(!s.empty())
                ans[i] = (s.top()-i);  
            
            // push the index of current temperature in the stack
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
		cin >> n;
		vector<int> a(n);
                    for(int i = 0; i < n; i++)
                              cin>>a;
		Solution obj;
		vector <int> s = obj.dailyTemperatures(a);
		
                    for(auto x: s)
                              cout<<x<<" ";
		
		cout<<endl;
	}
	return 0;
}