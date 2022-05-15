//  Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// TC->O(nlogn) | SC->O(n)
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        /*
        // Using STL sorting
        // O(nlogn)
         sort(s.begin(), s.end(), [&](char a, char b) -> bool {
           return (mp[a] != mp[b]? mp[a] > mp[b] : a < b);
        });
        */
        
        /*
        The idea is to use max heap with nodes containing a pair {frequency, character}. 
        Since the first element of the pair is frequency, we don't need to pass a custom comparator.           
        Max heap will be constructed on the basis of frequency of characters, i.e. the root will contain the character with maximum frequency.*/


        // Using Max-heap -> freq, char
        // O(log(n))
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        
        // O(n)
        s = "";
        while(!pq.empty()){
            s += string(pq.top().first, pq.top().second); // frequency times the character
            pq.pop();
        }
        
        return s;
    }
};
int main()
{
          string s;
          cin>>s;
          Solution obj;
          s = obj.frequencySort(s);
          cout<<s;
}
