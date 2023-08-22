// https://codeforces.com/contest/1779/problem/A

#include<bits/stdc++.h>
using namespace std;

/*
Notice that lamps cannot change direction, it is only allowed to swap adjacent ones.
*/

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    string ac1 = "RL";
    string ac2 = "LR";
  
    size_t val1 = s.find(ac1);
    size_t val2 = s.find(ac2);
    
    if (val1 != string::npos){
        cout<<"0"<<endl;
    }
    else if(val2 != string::npos){
        cout<<val2 + 1<<endl;
    }else{
        cout<<"-1"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}