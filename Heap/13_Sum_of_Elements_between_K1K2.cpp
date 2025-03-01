// Sum of Elements between k1 smallest and k2 smallest numbers
// Problem link:
// https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long kthSmallest(long long arr[], long long N, long long K){
        // Max-Heap
        priority_queue<long long> max_heap;
        for(auto i = 0; i < N; i++){
            max_heap.push(arr[i]);
            if(max_heap.size() > K)
                max_heap.pop();
        }
        return max_heap.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first = kthSmallest(A, N, K1);
        long long second = kthSmallest(A, N, K2);
        long long sum = 0;
        for(auto i = 0; i < N; i++){
            if(A[i] > first && A[i] < second)
                sum += A[i];
        }
        return sum;
    }
};

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}