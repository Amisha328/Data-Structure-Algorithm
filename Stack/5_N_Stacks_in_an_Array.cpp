// "N" Stacks in an Array
// Problem link: 
// https://www.codingninjas.com/codestudio/problem-details/n-stacks-in-an-array_1164271

class NStack
{
public:
    // Initialize your data structure.
    int *arr, *top, *next;
    int n, s;
    int freespot;
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        freespot = 0;
        
        // initialize top
        for(int i = 0; i < n; i++)
            top[i] = -1;
        
        // initialize next
        for(int i = 0; i < s; i++)
            next[i] = i+1;
        
        // update the last index of next array as -1
        next[s-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check overflow
        if(freespot == -1)
            return false;
        
        // find index
        int idx = freespot;
        
        // update freespot
        freespot = next[idx];
        
        // insert element into the array
        arr[idx] = x;
        
        // update next 
        // since now arr[idx] has element now next[idx] reperents the next of top of stack
        next[idx] = top[m-1];
        
        // update top
        top[m-1] = idx;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // underflow condition when stack/array is empty
        if(top[m-1] == -1)
            return -1;
        
        // move reverse of push operations
        
        // find index
        int idx = top[m-1];
        
        // update the top
        top[m-1] = next[idx];
        
        // update the next
        next[idx] = freespot;
        
        // update the freespot
        freespot = idx;
        
        return arr[idx];
    }
};