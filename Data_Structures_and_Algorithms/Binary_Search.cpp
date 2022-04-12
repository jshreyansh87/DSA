#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int target){
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    
    int arr[] = {1, 3, 5, 8, 10, 15, 20, 34, 64, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 34;

    int pos = binary_search(arr, 0, size - 1, target);

    if(pos == -1){
        cout << "Target not found" << endl;
    }
    else{
        cout << "Target found at position " << pos << endl;
    }

    return 0;
}