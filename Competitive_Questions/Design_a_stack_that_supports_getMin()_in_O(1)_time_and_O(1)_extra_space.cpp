// Problem Statement => https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack <int> st;    // contains all elements
    int mini;      // carries minimum number
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        
        // when stack is empty then push the 1st element and it is mini
        if(st.empty()){
            st.push(data);
            mini = data;
        }
        else{
            // if data is smaller then current mini then push a new number in
            // then stack which can help us to find the previous minimum
            // because the mini has changed here. New number = 2 * data - mini
            if(data < mini){
                st.push(2 * data - mini);
                mini = data;
            }
            else{
                // if data is >= mini then normally push it
                st.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(st.empty()){
            return -1;
        }
        
        int curr = st.top();
        st.pop();

        // if curr top is > mini then simply return top and pop it
        if(curr > mini){
            return curr;
        }
        else{
            // else find the previous mini that was should become the 
            // current mini now and accordingly change values
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if(st.empty()){
            return -1;
        }
        int curr = st.top();

        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return st.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(st.empty()){
            return -1;
        }
        return mini;
    }  
};