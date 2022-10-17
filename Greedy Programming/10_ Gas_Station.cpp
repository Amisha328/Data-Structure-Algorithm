//  Gas Station
// Problem link:
// https://leetcode.com/problems/gas-station/
// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/gas-tank_699834

/*
Intution: - Greedy Approach
At each stage we always select the best starting point, i.e, starting point that can get the car 
to the next station(Greedy Approach). 
If the car can get to the next station, then surely the car will complete the round trip if it is possilbe.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int curr_gas = 0, total_gas = 0;
        for(int i = 0; i < n; i++)
        {
            curr_gas += gas[i]-cost[i];
            // add up all of the left side gas to total. 
            // If it's negative finally, return -1 since it's impossible to return the starting gas station's index.
            total_gas += gas[i]-cost[i];
            // if the current gas sum is negative, reset it and let the car start from next point.
            if(curr_gas < 0)
            {
                start = i+1;
                curr_gas = 0;
            }
        }
        if(total_gas >= 0) return start;
        else return -1;
    }
};