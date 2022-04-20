#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){
    int currSum = arr[0], maxSum = arr[0];

    for(int i = 0; i < n; i++){
        if(currSum >= 0){
            currSum += arr[i];
        }
        else{
            currSum = arr[i];
        }

        if(currSum > maxSum){
            maxSum = currSum;
        }
    }

    return maxSum;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Sum of Sub Array is " << kadane(arr, n) << endl;

    return 0;
}