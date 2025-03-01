// Rotate Matrix 90 Degree Clockwise
// Problem link:
// https://www.codingninjas.com/studio/problems/rotate-clockwise_4607762?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// TC: O(N^2) ASC: O(1)
void reverseArray(vector<int> &arr, int n){
    int p1 = 0, p2 = n-1;
    while(p1 < p2){
        swap(arr[p1], arr[p2]);
        p1++;
        p2--;
    }
}
void rotateClockwise(int n, vector < vector < int >> & nums) {
    // Transpose the matrix
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            swap(nums[i][j], nums[j][i]);
        }
    }

    // reverse each row
    for(int i = 0; i < n; i++){
        //reverse(nums[i].begin(), nums[i].end()); // OR
        reverseArray(nums[i], n);
    }
}