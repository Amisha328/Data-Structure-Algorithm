// Last Stone Weight
// Problem link:
// https://leetcode.com/problems/last-stone-weight/

#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) 
{
        sort(stones.begin(), stones.end());
        int n = stones.size()-1;
        while(stones.size() > 1)
        {
            int n = stones.size()-1;
            int stone1 = stones[n];
            int stone2 = stones[n-1];
            stones.pop_back();
            stones.pop_back();
            if(stone1 != stone2)
                stones.push_back(stone1-stone2);
            sort(stones.begin(),stones.end());
        }
        if(stones.size() == 0) return 0;
        return stones[0];
}
