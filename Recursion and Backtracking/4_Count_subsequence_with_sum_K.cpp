// Count Subsequences with a sum equal to k.
// TC-> O(2^n)

#include<bits/stdc++.h>
using namespace std;

// Method 1:
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

          // not pick/take, this index into the subsequence
         int right = check(idx+1, arr, temp, sum);

         return left+right;
}

int main(){
     int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    int sum;
    cin>>sum;
    cout<< check(0, arr, 0, sum);

    return 0;
}

// Method 2:
void check(int idx, vector<int> &arr, int temp, int sum, int &count){
          if(idx == arr.size())
          {
                    if(temp == sum) {
                        count++;
                    }
                    return; 
          }

          // take/pick the particular index into the subsequence
          temp += arr[idx];

          check(idx+1, arr, temp, sum, count);

          temp -= arr[idx];

          // not pick/take, this index into the subsequence
          check(idx+1, arr, temp, sum, count);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    int sum;
    cin>>sum;
    int count = 0;
    check(0, arr, 0, sum, count);
    cout<<count<<endl;

    return 0;
}
