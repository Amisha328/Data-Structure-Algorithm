// All Majority Elements
// Find all elements that appear more than ⌊ n/3 ⌋ times.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>


signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    // This is Using the Boyer Moore Voting Algorithm.
    // There can be at max only 2 majority element when the condition is n/3.
    // So this Algorithm Keeps track of 2 Elements at Max and will also print a null vector when there isn't any Majority Element.
    int res1 = 0, c1 = 1;
            int res2 = 0, c2 = 0;
            
            for(int i = 1; i <  v.size(); i++)
            {
                if(v[res1] == v[i])
                    c1++;
                else if(v[res2] == v[i])
                    c2++;
                else if(c1 == 0)
                {
                    res1 = i;
                    c1 = 1;
                }
                else if(c2 == 0)
                {
                    res2 = i;
                    c2 = 1;
                } 
                else
                {
                    c1--;
                    c2--;
                }
            }

            c1 = c2 = 0;
            vector<int> ans;
            for(int i = 0; i < v.size(); i++)
            {
                if(v[res1] == v[i])
                    c1++;
                else if(v[res2] == v[i])
                    c2++;
            }

            if(c1 > (v.size())/3)
               ans.push_back(v[res1]);
            if(c2 > (v.size())/3)
                ans.push_back(v[res2]);

            for(auto x: ans)
                cout<<x<<" ";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)