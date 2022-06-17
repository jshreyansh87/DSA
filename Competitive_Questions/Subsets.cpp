// Problem Statement => https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector <int> output, int index, vector<vector<int>>& ans){
        // approach => run an index in the array and for each element exclude and 
        //              include it once in the output and increment the index
        
        // base case (when index is out of array add the output array in answer and return)
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        // exclude the current element in answer
        solve(nums, output, index + 1, ans);
        
        // include the current element in answer
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> output;
        int index = 0;
        
        solve(nums, output, index, ans);
        
        return ans;
    }
};