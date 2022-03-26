// Chocolate Distribution Problem
// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/#
// https://www.codingninjas.com/codestudio/library/chocolate-distribution-problem

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // TC->O(nlogn) | SC->O(1)
    long long findMinDiff(vector<long long> a, long long n, long long m){
        if(m > n) return -1;
        
        sort(a.begin(), a.end());
        long long res = a[m-1] - a[0];
        for(long long i = 1; (i+m-1) < n; i++)
        {
            res = min(res, a[m+i-1]-a[i]);
        }
        
        return res;
    
    }   
};

int main()
 {
	long long n;
	cin>>n;
	vector<long long> a;
	long long x;
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
		
	long long m;
	cin>>m;
	Solution ob;
	cout<<ob.findMinDiff(a,n,m)<<endl;
	return 0;
}  