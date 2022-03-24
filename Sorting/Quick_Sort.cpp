// https://practice.geeksforgeeks.org/problems/quick-sort/1
// https://www.codingninjas.com/codestudio/problem-details/quick-sort_983625

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    int partition (int arr[], int low, int high)
    {
       // Lomuto Partition
       /*
       int pivot = arr[high];
       int i = low-1;
       for(int j = low; j <= high; j++)
       {
           if(arr[j] < pivot)
           {
               i++;
               swap(arr[i], arr[j]);
           }
       }
       
       swap(arr[i+1], arr[high]);
       return (i+1);
       */
       
       // Hoare Partition
       int i = low-1, j = high+1;
       int pivot = arr[low];
       while(true)
       {
           do
           {
               i++;
           }while(arr[i] < pivot);
           
           do
           {
               j--;
           } while(arr[j] > pivot);
           
           if(i >= j) return j;
           swap(arr[i], arr[j]);
        }
       
    }
    public:
    void quickSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int pivot = partition(arr, low, high);
            // quickSort(arr, low, pivot-1);
            quickSort(arr, low, pivot);
            quickSort(arr, pivot+1, high);
        }
    }
};

int main()
{
    int arr[1000],n,i;
    cin>>n;
    for(i=0;i<n;i++)
      cin>>arr[i];
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
} 


// Best Case: TC->theta(nlogn) | SC->theta(logn)
// Worst case: TC-> theta(n^2) | SC->theta(n)