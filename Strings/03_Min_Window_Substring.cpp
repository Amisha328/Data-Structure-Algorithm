#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
        map<char, int> mp;
        for(auto it: t)
            mp[it]++;
        int i = 0, j = ;
        string seq = "";
        while(j-i >= t.size() && j < s.size()){
            map<char,int> m(mp);
          //   for(auto x: m)
          //           cout<<x.first<<" "<<x.second<<endl;
            // if map has char at s[j]
            // cout<<"j = "<<j<<endl;
            while(!m.empty())
            {
                if(m.find(s[j]) != m.end())
                {
                    m[s[j]]--;
                    cout<<"s[j] = "<<s[j]<<endl;
                    for(auto x: m)
                              cout<<x.first<<" "<<x.second<<endl;
                }
                   
                if(m[s[j]] == 0) m.erase(s[j]);
                j++;
                //cout<<"j = "<<j<<endl;
            }
            if(m.empty()) seq = s.substr(i,j);
            cout<<seq<<endl;
            if(m.empty()){
                i++;
                j = i;
            }
        }
        return seq;
    }
int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s,t);
    return 0;
}