// Problem Statement => https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int mid;
        
        while(l <= r){
            mid = l + (r - l) / 2;
            
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                return mid;
            }
            else if(arr[mid] < arr[mid + 1]){
                l = mid + 1;
            }
            else if(arr[mid] < arr[mid - 1]){
                r = mid - 1;
            }
        }
        return -1;
    }
};