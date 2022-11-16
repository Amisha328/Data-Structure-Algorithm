// Maximum Length of a Concatenated String with Unique Characters
// Problem link:
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// https://www.codingninjas.com/codestudio/problem-details/string-concatination_2195424

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // function for checking uniqueness of the string
    int maxi = 0;
    bool is_unique(string& str)
    {
        set<char> st;
        for(auto ch: str){
            if(st.count(ch))
                return false;
            st.insert(ch);
        }
        return true;
    }
    
    void helper(vector<string>& arr, int i, int n, string curr)
    {
        // if we have got duplicate int our result then simply return
        
        if(is_unique(curr) == false)
            return;
        
        // base case
        
        if(i == n)
        {
            // update maxi
            
            if(curr.size() > maxi)
            {
                int size = curr.size();
                
                maxi = max(maxi, size);
            }
            
            return;
        }
        
        // we have two options either include the curr string or exclude
        
        // include the curr string
        
        helper(arr, i + 1, n, curr + arr[i]);
        
        // exclude the curr string
        
        helper(arr, i + 1, n, curr);
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        // call helper function
        
        helper(arr, 0, n, "");
        
        return maxi;
    }
};