#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

bool validBrackets(string s) {
    stack<char> stk;
    for(int i=0;i<s.length();i++)
    {
            if(stk.empty())
            {
                if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stk.push(s[i]);
                else
                return false;
            }
            else if(s[i]=='(' || s[i]=='[' || s[i]=='{')  stk.push(s[i]);
            else
            {
                if(s[i]==')' && stk.top()=='(') 
                stk.pop();
                else if(s[i]==']' && stk.top()=='[')
                stk.pop();
                else if(s[i]=='}' && stk.top()=='{')
                stk.pop();
            }

        }
        if(stk.empty()) return true;
        else return false;

}


int main(){
    eff;
    string s;
    getline(cin,s);
    if(validBrackets(s))
    cout<<"valid\n";
    else
    cout<<"invalid\n";
    return 0;
}