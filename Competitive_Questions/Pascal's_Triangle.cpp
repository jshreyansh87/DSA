// Problem Statement => https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> pascalTriangle;
    for(int i = 0; i < n; i++){
        vector<long long int> currRow(i + 1, 0);
        currRow[0] = 1;
        currRow[i] = 1;
        
        for(int j = 1; j < i; j++){
            currRow[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
        
        pascalTriangle.push_back(currRow);
    }
    return pascalTriangle;
}