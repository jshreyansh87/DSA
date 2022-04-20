#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s >= e)
        return;
    
    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5,4,8,7,3,4,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array" << endl;
    print_array(arr,n);
    cout << endl;

    quickSort(arr, 0, n-1);

    cout << "Sorted Array" << endl;
    print_array(arr,n);
    cout << endl;

    return 0;
}