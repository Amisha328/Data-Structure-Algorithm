// Count Subsequences with sum equal to k.
// TC-> O(2^n)

#include<bits/stdc++.h>
using namespace std;

int check(int idx, vector<int> &arr, int temp, int sum){
          if(idx == arr.size())
          {
                    if(temp == sum) return 1;
                    else return 0;     
          }

          // take/pick the particular index into the subsequence
          temp += arr[idx];

          int left = check(idx+1, arr, temp, sum);

          temp -= arr[idx];

          // not pick/take, this index into the sunsequence
         int right = check(idx+1, arr, temp, sum);

         return left+right;
}

int main(){
    vector<int> arr = {1,2,1};
    int sum = 2;
    cout<< check(0, arr, 0, sum);

    return 0;
}