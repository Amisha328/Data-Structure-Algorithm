// Evaluate expression to True Boolean Parenthesization
// Problem Statement:https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    map<string,int> mp;
    int mod = 1003;
    int solve(string s, int i, int j, bool flag)
    {
        if(i > j) return 0;
        if(i == j)
        {
            if(flag == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        string key = to_string(i)+" "+to_string(j)+" "+to_string(flag);
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int ans = 0;
        for(int k = i+1; k < j; k+=2)
        {
            int lT = solve(s, i, k-1, true);
            int lF = solve(s, i, k-1, false);
            int rT = solve(s, k+1, j, true);
            int rF = solve(s, k+1, j, false);
            
            if(s[k] == '&')
            {
                if(flag == true)
                    ans += (lT * rT) % mod;
                else
                    ans += ((lT * rF) + (lF * rT) + (lF * rF)) % mod;
            }
            else if(s[k] == '|')
            {
                if(flag == true)
                    ans += ((lT * rF) + (lF * rT) + (lT * rT)) % mod;
                else
                    ans += ((lF * rF)) % mod;
            }
            else if(s[k] == '^')
            {
                if(flag == true)
                    ans += ((lT * rF) + (lF * rT)) % mod;
                else
                    ans += ((lT * rT) + (lF * rF)) % mod;
            }
        }
        
        return mp[key] = ans % mod;
        
    }
    int countWays(int N, string S){
        mp.clear();
        return solve(S, 0, N-1, true) % mod;
    }
};


int main()
{
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    return 0;
} 

// Time Complexity: O(N^3)
// Auxiliary Space: O(N^2)

 