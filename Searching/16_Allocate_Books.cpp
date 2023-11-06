// Allocate Books
/*
Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
*/

/*
x - axis -> no of pages
y - axis -> free var -> no of students
Graph: monotonically decreasing
cutoff point - m
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// maximum number of pages assigned to a student is minimum -> first occurnace
int predicate(vector<int>& arr, int n, int m, long long int pages){
    int noOfStudents = 1;
    long long int allocated_pages = 0;
    for(int i = 0; i < n; i++){
        if(allocated_pages + arr[i] <= pages) allocated_pages += arr[i];
        else{
            noOfStudents++;
            allocated_pages = arr[i];
        }
    }
    // if number of students is more than required (m) that means 
    // we need to alloacte more pages to a single person to reduce the number of sudents required
    // to increase value of mid we move to right hence L = M
    if(noOfStudents > m) return 0;
    else return 1;
}
int findPages(vector<int>& arr, int n, int m) {
    // number of students are more than number of books
    if(m > n) return -1;
    long long int L = *max_element(arr.begin(), arr.end())-1;
    long long int R = accumulate(arr.begin(), arr.end(), 0LL)+1;
    while(L + 1 < R){
        long long int M = L + (R - L)/2;
        if(predicate(arr, n, m, M) == 0) L = M;
        else R = M;
    }
    return R;
}

int main(){
    eff;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<findPages(arr, n, k);
    
    return 0;
}
