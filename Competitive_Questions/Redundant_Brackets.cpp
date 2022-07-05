// Problem Statement  =>   https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473

#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack <char> st;
    
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        
        // if the current char in string is an opening bracket or an operator
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // then push it in stack
            st.push(ch);
        }
        else{
            // else if it is a closing bracket
            if(ch == ')'){
                // and the top element is an opening bracket then expression
                // has redundant bracket
                if(st.top() == '('){
                    return true;
                }
                else{
                    // else pop all the operators
                    while(st.top() != '('){
                        st.pop();
                    }
                    // and the opening bracket corresponding to the current
                    // closing bracket
                    st.pop();
                }
            }
        }
    }
    
    return false;
}