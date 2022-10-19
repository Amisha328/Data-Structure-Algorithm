// Heap Sort
// Problem link: 
// https://practice.geeksforgeeks.org/problems/heap-sort/1/#


#include <bits/stdc++.h>
using namespace std;

// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
       int largest = i, left = 2*i+1, right = 2*i+2;
       if(left < n && arr[left] > arr[largest])
            largest = left;
       if(right < n && arr[right] > arr[largest])
        largest = right;
       if(largest != i){
           swap(arr[i], arr[largest]);
           heapify(arr, n, largest);
       }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    {
        // Moves from the last internal node to the root of the tree
        // and keep calling for heapify for every node it visits.
        // ((n-1)-1)/2 finds the last internal node or parent of the last node
       for(int i = (n-2)/2; i >= 0; i--){
           heapify(arr, n, i);
       }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Repeatedly swap the root with the last node, reduce heap size by one and perofrm heapify.
        buildHeap(arr, n);
        for(int i = n-1; i >= 0; i--){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}