// Problem Statement => https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countArr[3] = {0};
        
        for(int i = 0; i < nums.size(); i++){
            countArr[nums[i]]++;
        }
        
        int pos = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < countArr[i]; j++){
                nums[pos] = i;
                pos++;
            }
        }
    }
};