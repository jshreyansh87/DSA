// Problem Statement => https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // start from the top right element
        int rowIndex = 0;
        int colIndex = col - 1;
        
        while(rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];
            
            if(element == target){
                return true;
            }
            else if(element < target){
                rowIndex++;         // if target > element then search next row
            }
            else{
                colIndex--;         // if target < element then search previous col
            }
        }
        return false;
    }
};