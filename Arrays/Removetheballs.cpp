// Remove the balls
// Problem link:
// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-110/problems

// Problem statement:
/*
Imagine an imaginary array of length N containing balls. Given 2 arrays color and radius of length N
each, where color[i] represents the color of the ith ball while radius[i] represents the radius of
ith ball. If two consecutive balls have the same color and size, both are removed from the array. 
Geek wants to know the length of the final imaginary array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        for(int i = 0; i < color.size()-1; i++){
            if(color[i] == color[i+1] && radius[i] == radius[i+1]){
                color.erase(color.begin()+i);
                color.erase(color.begin()+i);
                radius.erase(radius.begin()+i);
                radius.erase(radius.begin()+i);
                i-= 2;
            }
        }
        return color.size();
    }
};

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}
