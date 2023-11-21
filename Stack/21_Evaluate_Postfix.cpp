// Evaluation of Postfix or Evaluate Reverse Polish Notation
// Problem link:
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Postfix expression evaluation
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x: tokens)
        {
            if(x == "+" || x == "-" || x == "*" || x == "/")
            {
                auto b = st.top();
                st.pop();
                
                auto a = st.top();
                st.pop();
                
                if(x == "+")
                    st.push(a+b);
                else if(x == "-")
                    st.push(a-b);
                else if(x == "*")
                    st.push(a*b);
                else
                    st.push(a/b);
            }
            else
                st.push(stoi(x));
        }
        return st.top();
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        int n;
        cin>>n;
        vector<string> exp(n);
        for(int i = 0; i < n; i++)
            cin>>exp[i];
        Solution ob;
        cout << ob.evalRPN(exp) << endl;
    }
    return 0;
}