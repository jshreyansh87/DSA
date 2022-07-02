// Problem Statement => https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104

#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack <char> st;
    
    for(int i = 0; i < expression.length(); i++){
        // for every current character in expression
        char currChar = expression[i];
        // if it is an opening bracket then push it
        if(currChar == '{' || currChar == '(' || currChar == '['){
            st.push(currChar);
        }
        else{
            // else check if the stack is empty then return false
                if(st.empty()){
                    return false;
                }
                else{
                    // else check if the closing bracket matches its 
                    // opening bracket at the top eleemnt in stack
                    if(currChar == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(currChar == ')' && st.top() == '('){
                    st.pop();
                }
                else if(currChar == ']' && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    
    return st.empty();
}