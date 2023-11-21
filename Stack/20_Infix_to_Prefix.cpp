// Infix To Prefix

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert an infix to prefix expression.
  string infixToPrefix(string s) {
        unordered_map<char, int> mp;
        mp.insert({'^',3});
        mp.insert({'*', 2});
        mp.insert({'/', 2});
        mp.insert({'+', 1});
        mp.insert({'-', 1});
        mp.insert({')', 0});
        
        stack<char> st;
        string res = "";
        
        for(int i = s.size()-1; i>= 0; i--)
        {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
                res += s[i];
            else if(s[i] == ')')
                st.push(s[i]);
            // if a closing bracket is encountered pop all the elements 
            // till an opening bracket is encountered.
            else if(s[i] == '(')
            {
                while(st.top() != ')')
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
                while(!st.empty() && mp[s[i]] < mp[st.top()])
                {
                    res = res + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        // once the entire expression is traversed pop all remaining elements from
        // stack and add in the res
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string infix;
        cin >> infix;
        Solution ob;
        cout << ob.infixToPrefix(infix) << endl;
    }
    return 0;
}