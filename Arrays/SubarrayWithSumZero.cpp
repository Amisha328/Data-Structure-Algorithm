// Find the length of largest subarray with 0 sum
// problem link: https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // TC-> O(n)[array traversal]*O(logn)[hashmap] -> O(nlogn) | SC->O(n)
    int maxLen(vector<int>&A, int n)
    {   
        map<int, int> mp;
        int s = 0, max_len = 0;
        for(int i = 0; i < n; i++)
        {
            s += A[i];
            if(s == 0)
                max_len = i+1;
            else
            {
                if(mp.find(s) == mp.end())
                    mp[s] = i;
                else
                    max_len = max(max_len, i-mp[s]);
            }
            
        }
        return max_len;
    }
};

int main()
{
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;

    return 0; 
}
