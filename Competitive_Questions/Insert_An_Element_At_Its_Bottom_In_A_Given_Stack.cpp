// Problem Statement => https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& myStack, int x){
    // Approach => Recursively keep the current element aside and
    //             check when stack is empty then push x and return.
    //             Now push all the elements that were kept aside back in stack
    
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    int currElement = myStack.top();
    myStack.pop();
    
    // recursive call
    solve(myStack, x);
    
    myStack.push(currElement);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    
    solve(myStack, x);
    return myStack;
}