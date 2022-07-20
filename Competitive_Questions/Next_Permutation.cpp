// Problem Statement => https://www.codingninjas.com/codestudio/problems/next-permutaion_893046

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &permutation, int i, int j){
    while(i < j){
        swap(permutation[i], permutation[j]);
        i++;
        j--;
    }
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // if size of array is 0 or 1 return same array
    if(n == 0 || n == 1){
        return permutation;
    }
    
    // step 1 => from the 2nd last index traverse the array and find the
    // 1st element that is smaller than the element on its right and store its
    // index in "i"
    
    int i = n - 2;
    while(i >= 0 && permutation[i] >= permutation[i + 1]){
        i--;
    }
    
    // step 2 => from the last index find the 1st element that is greater than
    // the element at "i" and swap them
    
    if(i >= 0){
        int j = n - 1;
        while(j >= 0 && permutation[j] <= permutation[i]){
            j--;
        }
        swap(permutation[i], permutation[j]);
    }
    
    // step 3 => reverse the array after index "i"
    reverse(permutation, i + 1, n - 1);
    
    return permutation;
}