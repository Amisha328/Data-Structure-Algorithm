#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    eff;
    stack<char> stk;
    int count = 0;
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(!stk.empty() &&  stk.top()==s[i])
        {
            stk.pop();
            count++;
        }   
        else
        {
            stk.push(s[i]);
        }    

    }
    if(count%2==0)
        cout<<"No\n";
    else
        cout<<"Yes\n";    
    return 0;
}