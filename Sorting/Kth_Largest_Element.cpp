// https://leetcode.com/problems/kth-largest-element-in-an-array/ 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low-1;
        for(int j = low; j < high; j++)
        {
            if(arr[j] >= pivot)
            {
                i++;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[i+1], arr[high]);
        return (i+1);
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthLargest(int arr[], int l, int r, int k) {
            while(l <= r)
            {
                int p = partition(arr, l, r);
                if(p == k-1)
                    return arr[p];
                else if(p > k-1)
                    r = p-1;
                else
                    l = p+1;
            }
            
            return -1;
          
    }
};

int main()
{
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthLargest(a, 0, number_of_elements-1, k)<<endl;
    return 0;
}  