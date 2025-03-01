// Count number of Set Bits
// Problem link:
// https://practice.geeksforgeeks.org/problems/set-bits0143/1?

// TC -> O(number of set bits)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits(int N) {
        int cnt = 0;
        while(N > 0){
            N = N & (N-1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}