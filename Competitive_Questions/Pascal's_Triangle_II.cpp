// Problem Statement => https://leetcode.com/problems/pascals-triangle-ii/

#include <bits/stdc++.h>
using namespace std;


// Solution 1 work till rowIndex <= 27
class Solution1 {
private:
    long long int getCurrentIndexVal(long long int n, long long int r){
        // here r = column index value and n = row - 1 index value
        // if col val is 0 then return 1
        if(r == 0){
            return 1;
        }
        // if col val is 1 then return n
        else if(r == 1){
            return n;
        }
        
        // else find the value
        long long int numerator = 1, denominator = 1;
        for(long long int i = 0; i < r; i++){
            numerator *= n - i;
            denominator *= i + 1;
        }

        return numerator / denominator;
    }
    
public:
    vector<int> getRow(int rowIndex) {
        int k = rowIndex + 1;
        // initialize a vector with 0 at all index
        vector <int> currRow(k, 0);

        // calculate values for 1st half of the vector
        for(int i = 0; i <= (k / 2); i++){
            // find value with arguments row - 1 and column index
            currRow[i] = getCurrentIndexVal(k - 1, i);
        }

        // copy the values from 1st half, because each row is symmetrical from center
        for(int i = (k / 2) + 1; i < k; i++){
            currRow[i] = currRow[k - i - 1];
        }

        return currRow;
    }
};

// Solution 1 work till rowIndex <= 33
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<vector<int>> pascalTriangle;
        for(int i = 0; i < n; i++){
            vector<int> currRow(i + 1, 0);
            currRow[0] = 1;
            currRow[i] = 1;

            for(int j = 1; j < i; j++){
                currRow[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }

            pascalTriangle.push_back(currRow);
        }
        return pascalTriangle[rowIndex];
    }
};