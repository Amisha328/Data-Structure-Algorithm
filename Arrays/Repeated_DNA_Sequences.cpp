// Repeated DNA Sequences
// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
// You may return the answer in any order.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>


vector<string> findRepeatedDnaSequences(string s)
{
        int n = s.length();
        map<string,int> m;
        vector<string> v;
        
        // if(s.length() == 10)
        //     v.push_back(s);
        
        for(int i = 0; i < n; i++)
        {
            // using sliding window of size 10
            if(i+9 < s.length())
                m[s.substr(i,10)]++;
        }
        for(auto x: m)
        {
            if(x.second > 1)
                v.push_back(x.first);
        }
        
         return v;
}
signed main(){
    eff;
    int n;
    string s;
    getline(cin,s);
    vector<string> v = findRepeatedDnaSequences(s);
    for(auto x: v)
        cout<<x<<" ";
    return 0;
}