#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 


signed main(){
    eff;
    int q;
    cin>>q;
    stack<int> stk;

    while(q--)
    {
        int type;
        cin>>type;

        if(type == 1)
        {
            int n;
            cin>>n;
            stk.push(n);
        }
        else
        {
            if(stk.empty())
                cout<<"kuchbhi?\n";
            else
            {
                cout << stk.top() << "\n";
                stk.pop();
            }    
        }
        
    }
    return 0;
}