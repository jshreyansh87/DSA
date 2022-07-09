// Problem Statement => https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1: push all person in stack
        stack <int> st;
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        // step 2: pop two person and push one back among these two which does not know the other
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(M[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        // Step 3: Now, only 1 person is in stack so it is a potential celebrity
        // verify it by checking if everybody knows him and he knows nobody
        int potentialCandidate = st.top();
        int rowZeroCount = 0;
        for(int i = 0; i < n; i++){
            if(M[potentialCandidate][i] == 0){
                rowZeroCount++;
            }
        }
        
        if(rowZeroCount != n){
            return -1;
        }
        
        int colOneCount = 0;
        for(int i = 0; i < n; i++){
            if(M[i][potentialCandidate] == 1){
                colOneCount++;
            }
        }
        
        if(colOneCount != n - 1){
            return -1;
        }
        
        return potentialCandidate;
    }
};