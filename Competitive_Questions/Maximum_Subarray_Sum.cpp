// Problem Statement => https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_630526

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long int overAllSum = 0, currSum = arr[0];
    
    for(int i = 1; i < n; i++){
        if(currSum < 0 && arr[i] > currSum){
            currSum = arr[i];
        }
        else if(arr[i] + currSum >= arr[i]){
            currSum += arr[i];
        }
        
        if(currSum > overAllSum){
            overAllSum = currSum;
        }
    }
    
    return overAllSum;
}