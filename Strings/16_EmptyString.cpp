// Empty the String
// Problem link:
// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-120/problems


#include<bits/stdc++.h>
using namespace std;

// It will give TLE
// Naive solution for smaller inputs
// TC->O(N X N) SC-> O(1)
class Solution {
  public:
    
    int makeStringEmpty(string s) {
        int cnt = 0;
        // O(N * N)
        while(!s.empty()){
            auto i = s.find("geek"); // O(N)
            if (i == string::npos) return -1;
            s = s.substr(0, i) + s.substr(i+4, s.size()-1); // O(N)
            cnt++;
        }
        return cnt;
    }
};


// Efficient solution: TC->O(N) SC-> O(N)

class Solution {
  public:
    int makeStringEmpty(string s) {
        vector<char> v;
        int cnt = 0;
        for(auto c: s){
            v.push_back(c);
            int n = v.size();
            if(n >= 4 && v[n-1] == 'k' && v[n-2] == 'e' && v[n-3] =='e' && v[n-4] == 'g'){
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.pop_back();
                cnt++;
            }
        }
        if(!v.empty()) return -1;
        else return cnt;
    }
};