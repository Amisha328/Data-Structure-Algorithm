// Next Greater Element I
// Problme statement: Find the NGE for elements in nums1 in nums2.
// Problem link:
// https://leetcode.com/problems/next-greater-element-i/
// https://www.codingninjas.com/codestudio/problem-details/next-greater-element-i_3651446

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> s;
        vector<int> ans;
        
        for(int i = 0; i < nums2.size(); i++){
            while(!s.empty()){
                // if top element is less than the current element in array
                if(s.top() < nums2[i])
                {
                    // it is the NGE of top of stack element
                    m[s.top()] = nums2[i];
                    s.pop();
                }
                else break;
            }
            s.push(nums2[i]);
        }
        
        /*
        cout<<"Map\n";
        for(auto const &pair: m)
            cout<<pair.first<<endl;
        cout<<endl;
        */

        for(int i = 0; i < nums1.size(); i++){
            int val = m[nums1[i]];
            if(val == 0) ans.push_back(-1);
            else ans.push_back(val);
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution obj;
    vector<int> ans = obj.nextGreaterElement(nums1,nums2);

    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}