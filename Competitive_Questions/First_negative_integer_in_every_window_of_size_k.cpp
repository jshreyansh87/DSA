// Problem Statement => https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque <long long int> dq;
    vector <long long> ans;
    
    // process 1st window
    for(int i = 0; i < K; i++){
        // if element is a -ve number then add index in deque
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    // if deque is not empty then add element in vector else add 0
    if(!dq.empty()){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // for remaining part
    for(int i = K; i < N; i++){
        // removing elements from front of deque
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front();
        }
        
        // adding -ve elements from back of deque
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        // if deque is not empty then add element in vector else add 0
        if(!dq.empty()){
        ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    
    return ans;
 }

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}