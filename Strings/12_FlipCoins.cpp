// Silver and Gold Coin Flip
// Problem link:
// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-117/problems

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string flipCoins(int N, string s){
        if(N == 1 && s[0] == '1') return "Yes";
        if(N == 2 && ((s[0] == '1' && s[1] == '0') || (s[0] == '0' && s[1] == '1'))) return "No";
        for(int i = 0; i < N-1; i++){
           // cout<<"START: i = "<<i<<" i+1 = "<<i+1<<endl;
            if(s[i] == '0' && s[i+1] != '0'){
                //cout<<"Case 1"<<endl;
                s[i] = '1';
                s[i+1] = '0';
            }
            else if(s[i] == '0' && s[i+1] == '0') {
                //cout<<"Case 2"<<endl;
                s[i] = '1';
                s[i+1] = '1';
                ++i;
            }
           // cout<<"END : i = "<<i<<" i+1 "<<i+1<<endl;
        }
        for(auto x: s){
            if(x == '0') return "No";
        }
        return "Yes";
    }
};



int main(){
        int n; 
        cin >> n ; 
        string s; 
        cin >> s; 
        Solution obj;
        string ans = obj.flipCoins(n , s);
        cout << ans << "\n";
}
