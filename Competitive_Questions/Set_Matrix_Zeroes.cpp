// Problem Statement  =>   https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = true;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                col0 = false;
            }
            
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 1; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
            
            if(!col0){
                matrix[i][0] = 0;
            }
        }
    }
};

int main(){
    Solution s;

    vector<vector<int>> matrix;

    matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};

    cout << "\nOriginal Matrix" << endl;

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    s.setZeroes(matrix);

    cout << "\nOriginal Matrix" << endl;

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}