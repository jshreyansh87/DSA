// Problem Statement => https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> v(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            v[(i + k) % nums.size()] = nums[i];
        }
        
        nums = v;
    }
};