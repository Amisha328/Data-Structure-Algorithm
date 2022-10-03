// Eliminate Maximum Number of Monsters
// Problem link:
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

/*
Since the speed and distance for all the mosters are different and also some may start at closer distance while others may at further distance but have a faster speed.

Hence, from this we can conclude that taking distance or speed alone in consideration will not work.
So, we will take the time taken by monster to reach the city into consideration.
i.e., 
-> dist = speed * time
-> time = ceil(dist/speed)

Hence we will eliminate the monster will smaller arrival time first to kill maximum monsters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrivalTime;
        
        for(int i = 0; i < n; i++)
            arrivalTime.push_back((int)ceil((double)dist[i]/(double)speed[i]));
        
        sort(arrivalTime.begin(), arrivalTime.end());
        int killed = 0, curr_time = 0;
        for(int idx = 0; idx < n; idx++)
        {
            if(arrivalTime[idx] > curr_time)
                killed++;
            else
                break;
            curr_time++;
        }
        return killed;
    }
};