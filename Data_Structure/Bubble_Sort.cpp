#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    bool swapped;

    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

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

    bubble_sort(arr,n);

    cout << "Sorted Array" << endl;
    print_array(arr,n);
    cout << endl;

    return 0;
}