// Problem Statement  =>  https://www.codingninjas.com/codestudio/problems/circular-queue_1170058

#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    
    ~CircularQueue(){
        delete []arr;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // if queue is full
        if((front == -1 && rear == size - 1) || (rear == (front - 1) % (size - 1))){
            return false;
        }
        
        // if 1st element is being inserted
        if(front == -1){
            front = rear = 0;
        }
        // if rear is at last index then maintain cycle
        else if(rear == size - 1 && front != 0){
            rear = 0;
        }
        // else normal flow
        else{
            rear++;
        }
        
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        // if only 1 element was in queue and it is being pop
        if(front == rear){
            front = rear = -1;
        }
        // if rear is at last index then maintain cycle
        else if(front == size - 1){
            front = 0;
        }
        // else normal flow
        else{
            front++;
        }
        return ans;
    }
};