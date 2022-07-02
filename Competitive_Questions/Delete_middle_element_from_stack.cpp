// Problem Statement => https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& inputStack, int size, int count){
    // Approach => at each step recursively keep the top aside and
    //             increment the count, when count = size / 2, 
    //             then pop that element and return. Now, push all the
    //             top elements back that were kept aside

    // base case
    if(count == size / 2){
        inputStack.pop();
        return;
    }
    
    // store the top element and remove it for now
    int currElement = inputStack.top();
    inputStack.pop();
    
    // recursive call
    solve(inputStack, size, count + 1);
    
    // push the top back in stack
    inputStack.push(currElement);
}

void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
    solve(inputStack, N, count);
}