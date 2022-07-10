// Problem Statement => https://practice.geeksforgeeks.org/problems/max-rectangle/1/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  private:
  vector <int> getNextSmaller(int* arr, int n){
      vector<int> next(n);
      stack <int> st;
      st.push(-1);
      
      for(int i = n - 1; i >= 0; i--){
          int currElement = arr[i];
          
          while(st.top() != -1 && arr[st.top()] >= currElement){
              st.pop();
          }
          
          next[i] = st.top();
          st.push(i);
      }
      return next;
  }
  
  vector <int> getPrevSmaller(int* arr, int n){
      vector<int> prev(n);
      stack <int> st;
      st.push(-1);
      
      for(int i = 0; i < n; i++){
          int currElement = arr[i];
          
          while(st.top() != -1 && arr[st.top()] >= currElement){
              st.pop();
          }
          
          prev[i] = st.top();
          st.push(i);
      }
      return prev;
  }
  
  int largestRectangleArea(int* arr, int n){
      vector <int> next;
      next = getNextSmaller(arr, n);
      
      vector <int> prev;
      prev = getPrevSmaller(arr, n);
      
      int area = INT_MIN;
      for(int i = 0; i < n; i++){
          int l = arr[i];
          
          if(next[i] == -1){
              next[i] = n;
          }
          
          int b = next[i] - prev[i] - 1;
          
          int newArea = l * b;
          area = max(area, newArea);
      }
      
      return area;
  }
  
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // compute area for 1st row
        int area = largestRectangleArea(M[0], m);
        
        // for each remaining row
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                // if current element is not 0 then add the element above to get total height in that column
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else{
                    M[i][j] = 0;
                }
                
                // compute area for current row
                // and store the max area
            }
                area = max(area, largestRectangleArea(M[i], m));
        }
        
        return area;
    }
};