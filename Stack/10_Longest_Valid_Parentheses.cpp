// Longest Valid Parentheses Substring
// Problem link:
// https://leetcode.com/problems/longest-valid-parentheses/
// https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1/#
// https://practice.geeksforgeeks.org/problems/3b47f0ad00f953dd514235ddec54e39fdc297dda/1/#
// https://www.codingninjas.com/codestudio/problem-details/longest-valid-parentheses_1089563

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // Stack Solution
        // TC-> O(n) | SC -> O(n)
        /*
        int max_possible = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(' )
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                {
                    int len = i - st.top();
                    max_possible = max(max_possible, len);
                }
            }
        }
        return max_possible;
        */
        
        // No Stack Solution
        // TC-> O(n) | SC -> O(1)
        
        int close = 0, open = 0;
        int max_len = 0;
        // front -> end
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close)
            {
                int len = open + close;
                max_len = max(max_len, len);
            }
            else if(close > open)
                close = open = 0;
        }
        
        close = open = 0;
        // end -> front
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close)
            {
                int len = open + close;
                max_len = max(max_len, len);
            }
            else if(open > close)
                close = open = 0;
        }
        
        return max_len;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.longestValidParentheses(s);
    return 0;
}