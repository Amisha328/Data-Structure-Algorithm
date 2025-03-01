// Break a Palindrome
// Problem link:
// https://leetcode.com/problems/break-a-palindrome/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        // it is only possible to perform the replacement if length is greater than 1.
        if(n == 1) return "";
        
        // check for the first non 'a' character
        for(int i = 0; i < n/2; i++)
        {
            if(palindrome[i] != 'a')
            {
                // change it into 'a' to form the lexicographically smallest.
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // if we do reach the middle of the palindrome without returning, 
        // i.e., we have not found a non 'a' character, 
        // thus we know that the whole or till mid palindrome consists of a's (like "aaaaa" or "aba")
        
        // Hence, we replace the last character to 'b'
        palindrome[n-1] = 'b';
        return palindrome;
    }
};