// Nearest Smaller to left or Previous Smaller Element
// Problem link:
// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/#


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> s;
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && s.top() >= a[i])
                s.pop();
            if(s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();
            
            s.push(a[i]);
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends