// Problem Statement => https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // thimk of 2d matrix as a linear array and find start and end index
        int start = 0, end = row * col - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            // map the mid value index of assumed linear array to 2d matrix
            int element = matrix[mid / col][mid % col];
            
            if(element == target){
                return true;
            }
            else if(element < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }
};