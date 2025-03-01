// Basic Calculator
// Problem link:
// https://leetcode.com/problems/basic-calculator/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sign = 1, currNo = 0, ans = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9'){
                    currNo = s[i]-'0';
                while(i+1 < s.size() && (s[i+1] >= '0' && s[i+1] <= '9'))
                {
                    currNo = currNo * 10L + s[i+1]-'0';
                    i++;
                }
                currNo = currNo * sign;
                ans += currNo;
                sign = 1;
            }
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                ans = ans * st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
            
        }
        return ans;
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
        cout << ob.calculate(exp) << endl;
    }
    return 0;
}