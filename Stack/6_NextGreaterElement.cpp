// NGR | Nearest Greater to right | Next Largest Element
// Problem link: 
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/#
// https://www.codingninjas.com/codestudio/problem-details/next-greater-element_920451

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

vi nextGreaterElements(vi &arr)
{
    int n = arr.size();
    vi ans(n);

    stack<int> s;
        for(int i = n-1; i >= 0 ;i--)
        {
            while(!s.empty() && s.top() <= arr[i])
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
    vi ans = nextGreaterElements(arr);

    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}