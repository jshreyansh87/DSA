#include <bits/stdc++.h>
using namespace std;

void merge(int * arr, int s, int e){
    // find mid
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // allocate memory to new arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values in new arrays
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1] <= second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    // delete / free the memory
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e){
    // base case
    if(s >= e){
        return;
    }

    // find mid
    int mid = s + (e - s) / 2;

    // sort left part of array
    mergeSort(arr, s, mid);
    // sort right part of array
    mergeSort(arr, mid + 1, e);

    // merge arrays
    merge(arr, s, e);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {3,6,2,21,4,212,34};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before: ";
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Array After: ";
    printArray(arr, n);
}