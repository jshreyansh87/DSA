// Problem Statement => https://www.codingninjas.com/codestudio/problems/sort-0-1_624379

#include <bits/stdc++.h>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
    // take 2 pointers such that elements on left of low will be 0 and
    // elements on right of high will be 1
    int low = 0, high = size - 1;
    
    // until low crosses high
    while(low <= high){
        // while element at low is 0 keep on incrementing it because it is
        // in correct place
        while(input[low] == 0){
            low++;
        }
        // while element at high is 1 keep on decrementing it because it is
        // in correct place
        while(input[high] == 1){
            high--;
        }
        
        // now element at low is 1 and high is 0, so check if low <= high
        // then swap it and update pointers
        if(low <= high && input[low] == 1 && input[high] == 0){
            swap(input[low], input[high]);
            low++;
            high--;
        }
    }
}