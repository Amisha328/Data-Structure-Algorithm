// Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    string s;
    cin>>s;
    int n=s.length();

    int l = 0, r = 0, max_len = 0;
    set<char> st;
    while(r < n)
    {
        if(st.find(s[r]) == st.end())
        {
            st.insert(s[r]);
            max_len = max(max_len, r-l+1);
            r++;
        }
        else
        {
            st.erase(s[l]);
            l++;
        }
    }

    cout<<max_len;
        

    return 0;
}