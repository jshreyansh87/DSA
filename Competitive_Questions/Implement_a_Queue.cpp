// Problem Statement  =>  https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        size = 5000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    
    ~Queue() {
        delete [] arr;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rear == size){
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear++] = data;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else{
            int val = arr[qfront++];
            
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            
            return val;
        }
    }

    int front() {
        if(qfront == rear){
            return -1;
        }
        return arr[qfront];
    }
};