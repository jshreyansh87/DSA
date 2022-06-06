// Problem Statement => https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        
        for(int i = 1; i < n; i++){
            if(nums[i - 1] > nums[i]){
                count++;
            }
        }
        
        if(nums[n - 1] > nums[0]){
            count++;
        }
        
        return count <= 1;
    }
};