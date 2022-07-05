// Problem Statement  =>   https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
    // if length of string is odd then expression is invalid
    // because number of open bracket = number of closing bracket
    // so there sum is always even
  if(str.length() % 2 == 1){
      return -1;
  }
    
    stack <char> st;
    // for every char in str
    for(int i = 0; i < str.length(); i++){
        // push the open bracket in stack
        if(str[i] == '{'){
            st.push(str[i]);
        }
        else{
            // if stack is not empty and top element is opeening bracket
            if(!st.empty() && st.top() == '{'){
                // then pop the opening bracket
                st.pop();
            }
            else{
                // else push the current char in stack
                st.push(str[i]);
            }
        }
    }
    // now all the valid pair of brackets are removed from stack
    
    // count the number of open and closing bracket
    int openBracketCount = 0, closeBracketCount = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            openBracketCount++;
        }
        else{
            closeBracketCount++;
        }
        st.pop();
    }
    
    // calculate the ans and return it
    int ans = ((openBracketCount + 1) / 2) + ((closeBracketCount + 1) / 2);
    
    return ans;
}