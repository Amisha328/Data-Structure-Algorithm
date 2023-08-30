// Sort Vowels in a String
// Problem link:
// https://leetcode.com/problems/sort-vowels-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(char a, char b){
        return ((int)a < (int)b);
    }
    bool checkVowel(char x){
        if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        string v = "";
        for(auto x: s){
            if(checkVowel(x)) v += x;
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int k = 0;
        for(int i = 0; i < s.size(); i++){
            if(checkVowel(s[i])) s[i] = v[k++];
        }
        return s;
    }
};