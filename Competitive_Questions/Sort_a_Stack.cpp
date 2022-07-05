// Problem Statement  =>   https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int insertElement){
    // Approach => until stack is empty or the current element is smaller or
    //             equal to the element to be inserted keep the top element
    //             aside and recursively call this function.
    //             Now, when the recursive call ends then stack is either empty
    //             or the top element is stack is smaller than equal to element
    //             that is being inserted, so push that element and return.
    //             Push all the elements that were kept aside back into stack.
    
    // base case
    if(stack.empty() || stack.top() <= insertElement){
        stack.push(insertElement);
        return;
    }
    
    // keep the current element aside
    int num = stack.top();
    stack.pop();
    
    // recursive call
    sortedInsert(stack, insertElement);
    
    // push the element kept aside in stack
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
    // Approach => until stack is empty keep the top element aside and
    //             and recursively call this function. Now, when the recursive
    //             call returns then stack is empty, so start pushing the
    //             the elements that were kept aside in a sorted manner
    
    // base case => return when stack is empty
	if(stack.empty()){
        return;
    }
    
    // keep the current element aside
    int num = stack.top();
    stack.pop();
    
    // recursive call
    sortStack(stack);
    
    // push the element kept aside in sorted manner
    sortedInsert(stack, num);
}