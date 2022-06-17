#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e){
    // let pivot be 1st element in array
    int pivot = arr[s];

    // count number of element smaller than pivot
    int countElementSmallerThanPivot = 0;
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            countElementSmallerThanPivot++;
        }
    }

    // place pivot at correct position
    int pivotIndex = countElementSmallerThanPivot + s;
    swap(arr[pivotIndex], arr[s]);

    // put all elements smaller than pivot on its left
    // put all elements greater than pivot on its right
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        // increment i if arr[i] <= pivot
        while(arr[i] <= pivot){
            i++;
        }
        // decrement j if arr[i] <= pivot
        while(arr[j] > pivot){
            j--;
        }
        // swap element at index i and j
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    // base case
    if(s >= e){
        return;
    }
    // find pivot index by partition
    int p = partition(arr, s, e);

    // sort left side of pivot
    quickSort(arr, s , p - 1);
    // sort right side of pivot
    quickSort(arr, p + 1, e);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {6,6,-6,-2,-4,-6,2,-6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before: ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Array After: ";
    printArray(arr, n);
}