// Evaluation of Prefix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Prefix expression evaluation
    int evalPrefix(vector<string>& tokens) {
        stack<int> st;
        for(int i = tokens.size()-1; i >= 0; i--)
        {
            auto x = tokens[i];
            if(x == "+" || x == "-" || x == "*" || x == "/" || x == "^")
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
                else if(x == "/")
                    st.push(a/b);
                else if(x == "^")
                {
                          int val = round(pow(b,a));
                          st.push(val);
                }
          
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
        cout << ob.evalPrefix(exp) << endl;
    }
    return 0;
}