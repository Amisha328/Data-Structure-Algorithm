// Box Stacking
// problem link:
// https://practice.geeksforgeeks.org/problems/box-stacking/1
// https://www.codingninjas.com/codestudio/problems/box-stacking_981279?leftPanelTab=0

/*
Point of differnece:
1) We can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are
   each strictly larger than those of the 2-D base of the higher box.
2) We can use multiple instances of the same type of box.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool check(vector<int> &baseBox, vector<int> &newBox){
            if(newBox[0] < baseBox[0] && newBox[1] < baseBox[1])
                    return true;
            return false;
        }
    
        int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
            if(curr == cuboids.size()) return 0;
            if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
    
            // include
            int take = 0;
            if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                take = cuboids[curr][2] + solve(cuboids, curr+1, curr, dp);
            
            // exclude
            int notTake = 0 + solve(cuboids, curr+1, prev, dp);
    
            return dp[curr][prev+1] = max(take, notTake);
        }
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        
        vector<vector<int>> cuboids;
        // Step 1: store all the combinations of dimensions
        // reason we can use multiple instances of the same type of box
        for(int i = 0; i < n; i++){
            cuboids.push_back({width[i],height[i],length[i]});
            cuboids.push_back({length[i],width[i],height[i]});
            cuboids.push_back({length[i],height[i],width[i]});
            cuboids.push_back({width[i],length[i],height[i]});
            cuboids.push_back({height[i],length[i],width[i]});
            cuboids.push_back({height[i],width[i],length[i]});
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Step3: Now apply LIS
        // Memoization
        vector<vector<int>> dp(6*n, vector<int>(6*n+1, -1));
        return solve(cuboids, 0, -1, dp);
    }
};


// Tabulation

class Solution{
    private:
        bool check(vector<int> &baseBox, vector<int> &newBox){
            if(newBox[0] < baseBox[0] && newBox[1] < baseBox[1])
                    return true;
            return false;
        }
    public:
    int maxHeight(int height[],int width[],int length[],int n)
    {
        
        vector<vector<int>> cuboids;
        // Step 1: store all the combinations of dimensions
        // reason we can use multiple instances of the same type of box
        for(int i = 0; i < n; i++){
            cuboids.push_back({width[i],height[i],length[i]});
            cuboids.push_back({length[i],width[i],height[i]});
            cuboids.push_back({length[i],height[i],width[i]});
            cuboids.push_back({width[i],length[i],height[i]});
            cuboids.push_back({height[i],length[i],width[i]});
            cuboids.push_back({height[i],width[i],length[i]});
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Step3: Now apply LIS

        // Tabulation
        vector<vector<int>> dp(6*n+1, vector<int>(6*n+1, 0));
        for(int curr = cuboids.size()-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // include
                int take = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + dp[curr+1][curr+1];
                
                // exclude
                int notTake = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][-1+1];
    }
};

// Space Optimization

class Solution{
    private:
        bool check(vector<int> &baseBox, vector<int> &newBox){
            if(newBox[0] < baseBox[0] && newBox[1] < baseBox[1])
                    return true;
            return false;
        }
    public:
    int maxHeight(int height[],int width[],int length[],int n)
    {
        
        vector<vector<int>> cuboids;
        // Step 1: store all the combinations of dimensions
        // reason we can use multiple instances of the same type of box
        for(int i = 0; i < n; i++){
            cuboids.push_back({width[i],height[i],length[i]});
            cuboids.push_back({length[i],width[i],height[i]});
            cuboids.push_back({length[i],height[i],width[i]});
            cuboids.push_back({width[i],length[i],height[i]});
            cuboids.push_back({height[i],length[i],width[i]});
            cuboids.push_back({height[i],width[i],length[i]});
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Step3: Now apply LIS
        // Space Optimization
        vector<int> currRow(6*n+1, 0);
        vector<int> nextRow(6*n+1, 0);
        
        for(int curr = cuboids.size()-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                
                // include
                int take = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + nextRow[curr+1];
                    
                // exclude
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};