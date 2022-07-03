// Implement a Queue using Array
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/queue-using-array-or-singly-linked-list_2099908

#include <bits/stdc++.h> 
class Queue {
public:
    int * arr;
    int start, end, currSize, maxSize;
    Queue() {
        maxSize = 100001;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (currSize == 0);
    }

    void enqueue(int data) {
        if (currSize == maxSize) {
              //cout << "Queue is full\nExiting..." << endl;
              exit(1);
         }
         if (end == -1) {
              start = 0;
              end = 0;
          } 
          else
              end = (end + 1) % maxSize;
          arr[end] = data;
           // cout << "The element pushed is " << data << endl;
          currSize++;
    }

    int dequeue() {
        if (start == -1) return -1;
        int popped = arr[start];
        if (currSize == 1) {
          start = -1;
          end = -1;
        } 
        else
          start = (start + 1) % maxSize;
        currSize--;
        return popped; 
    }

    int front() {
       if (start == -1) return -1;
       return arr[start];
    }
};