// Reverse Vowels of a String
// Problem link:
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        cout<<"size = "<<n<<"middle = "<<s[n/2]<<endl;
        int i = 0, j = n-1;
        while(i < j){
            cout<<"s[i] = "<<s[i]<<endl;
            cout<<"s[j] = "<<s[j]<<endl;
            if(vowel.count(s[i]) && vowel.count(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!vowel.count(s[i]))
                i++;
            else if(!vowel.count(s[j]))
                j--;
        }
        return s;
    }
};