// Problem Statement => https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        vector <int> ans(n);
        stack <int> st;
        st.push(-1);

        for(int i = n - 1; i >= 0; i--){
            int currElement = arr[i];

            while(st.top() != -1 && arr[st.top()] >= currElement){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        vector <int> ans(n);
        stack <int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            int currElement = arr[i];

            while(st.top() != -1 && arr[st.top()] >= currElement){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        // we know that for each rectangle the height is constant, so we need to maximize the width
        // to maximize width calculate for each height how much width can be occupied in front and back
        // of current height
        
        int size = heights.size();
        
        // find the index of 1st smaller element ahead of current height, because only upto that index
        // we can have a rectangle of current height
        vector <int> next;
        next = nextSmallerElement(heights, size);
        
        // find the index of 1st smaller element behind of current height, because only upto that index
        // we can have a rectangle of current height
        vector <int> prev;
        prev = prevSmallerElement(heights, size);
        
        // find max area
        int area = INT_MIN;
        for(int i = 0; i < size; i++){
            int l = heights[i];
            
            // next[i] is -1, then the area would be negative so put it at the last index
            if(next[i] == -1){
                next[i] = size;
            }
            
            int b = next[i] - prev[i] - 1;
            
            int newArea = l * b;
            
            area = max(area, newArea);
        }
        
        return area;
    }
};