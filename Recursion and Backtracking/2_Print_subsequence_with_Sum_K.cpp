// Printing Subsequence whose sum is K
// Take | Not - take

#include<bits/stdc++.h>
using namespace std;

void printSub(int idx, vector<int> &ds, vector<int> &arr, int temp, int sum){
          if(idx == arr.size())
          {
                    if(temp == sum) {
                              for(auto it: ds)
                                        cout<<it<<" ";
                              
                              cout<<endl;
                    }
                    return;
          }

          // take/pick the particular index into the subsequence
          ds.push_back(arr[idx]);
          temp += arr[idx];
          printSub(idx+1, ds, arr, temp, sum);
          temp -= arr[idx];
          ds.pop_back();

          // not pick/take, this index into the sunsequence
          printSub(idx+1, ds, arr, temp, sum);
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> ds;
    int temp = 0;
    int sum = 2;
    printSub(0, ds, arr, temp, sum);

    return 0;
}