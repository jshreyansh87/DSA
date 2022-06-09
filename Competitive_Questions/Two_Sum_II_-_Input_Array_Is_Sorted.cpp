// Problem Statement => https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0; i < numbers.size(); i++){
            int toFind = target - numbers[i];
            int s = i + 1, e = numbers.size() - 1;
            
            while(s <= e){
                int mid = s + (e - s) / 2;
                
                if(numbers[mid] == toFind){
                    return {i + 1, mid + 1};
                }
                else if(numbers[mid] > toFind){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
        }
        
        return {};
    }
};