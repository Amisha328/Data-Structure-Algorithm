// Find if Array Can Be Sorted
// https://leetcode.com/problems/find-if-array-can-be-sorted/description/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

// Approach 1:
// TC: O(n) | SC : O(n)

class Solution {
private:
    int setBits(int num){
        int cnt = 0;
        while(num){
            if(num & 1) cnt++;
            num = num >> 1;
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitSet(n);
        for(int i = 0; i < n; i++){
            bitSet[i] = setBits(nums[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] > nums[j] && bitSet[i] != bitSet[j]) return false;
            }
        } 

        return true;

    }
};

// Approach 2:
/*
We can only swap adjacent elements, with an additional condition that they have equal number of set bits.
This hints towards splitting array into some segments, such that every element in that segment has same number of bits.
We can only individual segments.
We dont need to sort every segment to check if the array becomes sorted or not, we only need maximum of prev segment and minimum of 
current segment, if prevMax > currMin, then array cannot be sorted whatsoever.
*/

// TC: O(n) | SC : O(1)
class Solution {
private:
    int setBits(int num){
        int cnt = 0;
        while(num){
            if(num & 1) cnt++;
            num = num >> 1;
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int prevMax = -1, currMax = -1, currMin = INT_MAX;
        int currBit = -1, prevBit = -1;

        for(auto it: nums){
            currBit = setBits(it);
            if(currBit == -1 || currBit == prevBit){
                prevBit = currBit;
                currMax = max(currMax, it);
                currMin = min(currMin, it);
            }
            else{
                if(prevMax > currMin) return false;
                prevMax = currMax;
                currMin = currMax = it;
                prevBit = currBit;
            }
        }

        if(prevMax > currMin) return false;
        return true;

    }
};

