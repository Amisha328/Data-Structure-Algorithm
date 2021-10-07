#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
        string s;
         getline(cin,s);
         map<char,int> m;
         int idx = 0;
         int  i = 0;
         int c = 0;
         // using sliding window technique
         while(i < 3)
         {
             // store first 3 char in map and mark their frequency
             m[s[i++]]++;
         }
         for(i = 3; i < s.size(); i++)
         {
             bool flag = false;
             for(auto x : m)
             {
                 // check if any of the char have frequency greater than 1
                 if(x.second > 1)
                 {
                     flag = true;
                     break;
                 }
             }
             // if all the char have frequency 1 then count the number of distinct char
             if(!flag)
                c++;
             
             // remove the first window first elements from map
             m[s[idx++]]--;
             // add the new char in map
             m[s[i]]++;
         }
        
        bool flag = false;
        for(auto x : m)
        {
            if(x.second > 1)
            {
                flag = true;
                break;
            }
        }
        
        if(!flag)
            c++;
        
       cout<<c; 
    return 0;
}