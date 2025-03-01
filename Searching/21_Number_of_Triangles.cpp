#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int predicate(int mid, int target){
          if(mid < target) return 0;
          else return 1;
}
int binarySearch(vector<int>& nums, int target) {
          int L = -1, R = nums.size();
          while(L + 1 < R){
                    int M = L + (R - L)/2;
                    if(predicate(nums[M], target) == 0) L = M;
                    else R = M;
          }
          // cout<<"R = "<<R<<endl;
          return L;
}


int main() {
    eff;
    int N;
    cin >> N;

    vector<int> sticks(N);
    for (int i = 0; i < N; ++i) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());

    int totalTriangles = 0;

    // Loop through the sticks and find triangles for each stick
    for (int i = 0; i < sticks.size() - 1; ++i) {
        for (int j = i + 1; j < sticks.size(); ++j) {
            int target = (sticks[i] + sticks[j]); // The third side of the triangle should be greater than the sum of first two sides
           // cout<<"i = "<<i<<" j = "<<j<<" target = "<<target<<endl;
            int pos = binarySearch(sticks, target);
            if(pos >= j)
            // We are subtracting (j+1) from the pos as the third side can only be after the index of 
            // first two sides => i (first side) , j (second side)
            totalTriangles += pos-j; // Count triangles using binary search
          //  cout<<totalTriangles<<endl;
        }
    }
    
    cout<<totalTriangles<<endl;
    return 0;
}
