// Problem Statement => https://www.codingninjas.com/codestudio/problems/two-stacks_983634

#include <bits/stdc++.h>
using namespace std;

class TwoStack {

public:
    int *arr;
    int top1, top2;
    int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1 + 1 < top2){
            arr[++top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top1 + 1 < top2){
            arr[--top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0){
            return arr[top1--];
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
            return arr[top2++];
        }
        else{
            return -1;
        }
    }
};