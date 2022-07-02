// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// Problem link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC-> O(NlogN) | SC-> O(1)
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const unsigned int M = 1000000007;
        
        // including the boundaries to calculate the distance of the cuts from the boundaries
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        
        long long int diff_h = 0, diff_w = 0;
        // finding the max distance between the two consecutive horizontal cuts
        for(int i = 0; i < horizontalCuts.size()-1; i++){
            if(diff_h < horizontalCuts[i+1]-horizontalCuts[i])
                diff_h = horizontalCuts[i+1]-horizontalCuts[i];
        }
        // finding the max distance between the two consecutive vertical cuts
        for(int j = 0; j < verticalCuts.size()-1; j++){
            if(diff_w < verticalCuts[j+1]-verticalCuts[j])
                diff_w = verticalCuts[j+1]-verticalCuts[j];
        }
        
        // calculate the area between the max cut space
        return (diff_h*diff_w)%M;
    }
};