// Infix To Postfix
// Problem link:
// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#
// https://www.codingninjas.com/codestudio/problem-details/infix-to-postfix_1382146


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
  string infixToPostfix(string s) {
        unordered_map<char, int> mp;
        mp.insert({'^',3});
        mp.insert({'*', 2});
        mp.insert({'/', 2});
        mp.insert({'+', 1});
        mp.insert({'-', 1});
        mp.insert({'(', 0});
        
        stack<char> st;
        string res = "";
        
        for(auto x: s)
        {
            if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
                res += x;
            else if(x == '(')
                st.push(x);
            // if a closing bracket is encountered pop all the elements 
            // till an opening bracket is encountered.
            else if(x == ')')
            {
                while(st.top() != '(')
                {
                    char ch = st.top();
                    res = res + ch;
                    st.pop();
                }
                st.pop(); // pop the opening bracket
            }
            else
            {
                // pop all the higher precedence operators from the stack
                // and add in the res.
                while(!st.empty() && mp[x] <= mp[st.top()])
                {
                    res = res + st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
        
        // once the entire expression is traversed pop all remaining elements from
        // stack and add in the res
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}