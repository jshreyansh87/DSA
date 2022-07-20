// Problem Statement => https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
   // taking 3 pointer such that elements on left of low are 0, elements on right of high are 2 and rest are 1's
    int low = 0, mid = 0, high = n - 1;
    
    // step 1 => traverse the array using mid pointer until it crosses the high pointer
    while(mid <= high){
        // if element at mid is 0 then swap it with low index element and increment both low and mid
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        // if element at mid is 1 then increment mid
        else if(arr[mid] == 1){
            mid++;
        }
        // if element at mid is 2 then swap it with high index element and decrement high only
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}