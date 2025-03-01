//  Next Greater Element II
// Problem statement: 
// Find first NGE, you could search circularly to find its next greater number.
// If it doesn't exist, return -1 for this number.
// Problem link:
// https://leetcode.com/problems/next-greater-element-ii/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /*
    Idea: It requires two traversal of array
    TC -> O(2* n)
    SC-> O(n)
    */
    vector<int> nextGreaterElements(vector<int>& arr)
    {
       int n = arr.size();
    
        // Approach 1:
        // Traversal from back to front
       vector<int> ans(n);
       stack<int> s;
       for(int i = 2*n-1; i >= 0; i--)
       {
            while(!s.empty() && s.top() <= arr[i%n])
                    s.pop();

            if(s.empty())
                    ans[i%n] = -1;
            else
                    ans[i%n] = s.top();  

             s.push(arr[i%n]);          
        }
        
        return ans;
        
        // Approach 2:
        // Traversal from front to back

        /*
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n*2; i++){
            while(!s.empty() && arr[s.top()] < arr[i%n]){
                ans[s.top()] = arr[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return ans;
        */
    }
};

int main()
{
   vector<int> arr = {2,5,3,7,4,8,1,2};
   //vector<int> arr = {1,2,3,4,3};
   Solution obj;
    vector<int> ans = obj.nextGreaterElements(arr);

    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}