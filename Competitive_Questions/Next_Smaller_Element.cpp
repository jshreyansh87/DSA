// Problem Statement => https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581

#include <bits/stdc++.h>
using namespace std;

#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Approach => start from the last element in array, we know nextSmallerElement
    //             for last element is -1, so push a -1 in stack, now traverse the array
    //             from last to first index and for each element if the top element of stack
    //             is smaller than current array element then store it as ans, else pop 
    //             elements until it is found.
    vector <int> ans(n);
    stack <int> st;
    st.push(-1);
    
    for(int i = n - 1; i >= 0; i--){
        int currElement = arr[i];
        
        while(st.top() >= currElement){
            st.pop();
        }
        ans[i] = st.top();
        st.push(currElement);
    }
    
    return ans;
}