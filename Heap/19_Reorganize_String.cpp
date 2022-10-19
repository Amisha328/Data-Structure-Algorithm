// Reorganize String or Rearrange characters
// Problem link:
// https://leetcode.com/problems/reorganize-string/
// https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/#
// https://www.codingninjas.com/codestudio/problem-details/rearrange-string_982765

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        
        unordered_map<char, int> freq;
        // max-heap
        priority_queue<pair<int, char>> max_heap;
        for(auto x: str)
            freq[x]++;
        
        for(auto it: freq)
            max_heap.push({it.second, it.first});
        
        str = "";
        while(max_heap.size() > 1){
            auto top1 = max_heap.top();
            max_heap.pop();
            auto top2 = max_heap.top();
            max_heap.pop();
            
            str += top1.second;
            str += top2.second;
            
            if(--top1.first > 0)
                max_heap.push(top1);
            if(--top2.first > 0)
                max_heap.push(top2);
            
        }
        
        if(max_heap.size()){
            if(max_heap.top().first == 1)
                str += max_heap.top().second;
            else
                return "-1";
        }
        
        return str;
    }
    
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  