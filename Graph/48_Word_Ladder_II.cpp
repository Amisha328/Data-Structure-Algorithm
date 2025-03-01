// Word Ladder II (For Interview)
// Problem link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

// Better Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        // stores used words from wordList of previous level
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty())
        {
            // stores the current level word sequence
            vector<string> v = q.front();
            q.pop();
            
            // erase all the words that has been
            // used in the previous level to transform
            while(v.size() > level)
            {
                level++;
                for(auto it: usedOnLevel)
                    st.erase(it);
            }
            
            string word = v.back();
            if(word == endWord)
                ans.push_back(v);
            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word))
                    {
                        // if transformed word exists in wordList
                        // add it to the sequence
                        v.push_back(word);
                        q.push(v);
                        
                        // mark the word as visited on that level
                        usedOnLevel.push_back(word);
                        // undo the changes made in word sequenece
                        // so that it can be changed to some other word
                        // on the same level
                        v.pop_back();
                    }
                }
                word[i] = original; // undo the character changes
            }
        }
        return ans;
    }
};
