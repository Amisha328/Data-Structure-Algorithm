// Nearest Greater to left or Previous Greater Element

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

vi pge(vi &arr)
{
    int n = arr.size();
    vi ans(n);

    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top() < arr[i])
            s.pop();

        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();  

        s.push(arr[i]);          
    }
    return ans;
}

int main(){
    eff;
    vi arr = {2,5,3,7,4,8,1,2};
    vi ans = pge(arr);

    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}