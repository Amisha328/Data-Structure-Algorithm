#include<bits/stdc++.h>
using namespace std;

// array size var declaraion as global
int n;
// Function to insert element in array
void insert(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
} // Time complexity of this function is O(n)

// Function to update element in array by adding element in array
void update(int arr[], int pos, int val, int cap)
{
    if(cap == n)
        cout<<"-1\n";
        
    int id = pos-1;
    for(int i = n-1; i>=id; i--)
         arr[i+1] = arr[i];

    arr[id] = val;
    n++;     
} // Time complexity of update() is O(n)

// Function to delete element in array
void deletion(int arr[], int pos)
{
    for(int i=pos-1;i<n-1;i++)
        arr[i] = arr[i+1];
    n--;
}

// update value at the position
void update_pos(int arr[], int pos, int val)
{
    arr[pos-1] = val;
} // Time complexity of update_pos() is O(1)

// Function to print array
void print(int arr[])
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// Function to sort array
void sort(int arr[])
{
    sort(arr,arr+n);
}

// Funtion to find element in array
void search(int arr[], int val)
{
    sort(arr);
    if (binary_search(arr, arr+n, val))
        cout << "\nElement found in the array";
    else
        cout << "\nElement not found in the array";
}

int main()
{
    cout<<"Enter size of array\n";
    cin>>n;
    int arr[n] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Enter elements of array\n";
    insert(arr,n);
    cout<<"\nDelete array element\n";
    int pos1;
    cout<<"\nEnter position to be deleted\n";
    cin>>pos1;
    deletion(arr, pos1);
    cout<<"Array after deletion\n";
    print(arr);
    cout<<"\n\nUpadate array\n";
    int pos, val, cap;
    cout<<"\nEnter position where element is to be added\n";
    cin>>pos;
    cout<<"Enter value that is to be added\n";
    cin>>val;
    cout<<"Enter capacity of the array\n";
    cin>>cap;
    update(arr,pos,val, cap);
    cout<<"Array after updation\n";
    print(arr);
    cout<<"\n\nUpdate array element\n";
    int pos2, val2;
    cout<<"\nEnter position where element is to be updated\n";
    cin>>pos2;
    cout<<"Enter value that is to be updated\n";
    cin>>val2;
    update_pos(arr,pos2,val2);
    cout<<"\nArray after updation\n";
    print(arr);
    cout<<"\n\nSort array\n";
    sort(arr);
    cout<<"\nArray after sorting\n";
    print(arr);
    cout<<"\n\nSearch element in array\n";
    int val1;
    cout<<"Enter element to be searched\n";
    cin>>val1;
    search(arr,val1);
    return 0;
}

// Time complexity of program is O(nlogn)
// Space complexity of program is O(n)