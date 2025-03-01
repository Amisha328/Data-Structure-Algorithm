// Valid Parentheses or Parenthesis Checker
// Problem link:
// https://leetcode.com/problems/valid-parentheses/
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

bool validBrackets(string s) {
    stack<char> stk;
    for(int i = 0; i < s.length(); i++)
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
    string s;
    getline(cin,s);
    if(validBrackets(s))
    cout<<"valid\n";
    else
    cout<<"invalid\n";
    return 0;
}