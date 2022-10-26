// Does Subsequence with given sum exist.

#include<bits/stdc++.h>
using namespace std;

bool printSub(int idx, vector<int> &ds, vector<int> &arr, int temp, int sum){
          if(idx == arr.size())
          {
                    if(temp == sum) {
                              for(auto it: ds)
                                        cout<<it<<" ";
                              
                              cout<<endl;
                              return true;
                    }
                    else return false;
                    
          }

          // take/pick the particular index into the subsequence
          ds.push_back(arr[idx]);
          temp += arr[idx];

          if(printSub(idx+1, ds, arr, temp, sum)) return true;

          temp -= arr[idx];
          ds.pop_back();

          // not pick/take, this index into the sunsequence
         if(printSub(idx+1, ds, arr, temp, sum)) return true;

         return false;
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> ds;
    int temp = 0;
    int sum = 2;
    if(  printSub(0, ds, arr, temp, sum))
          cout<<"Exist"<<endl;
    else
          cout<<"Does not exist"<<endl;

    return 0;
}