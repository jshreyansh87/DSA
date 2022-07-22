// Problem Statement => https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;

void solve(queue <int> &q, int n, int k){
    if(q.size() == n - k){
        return;
    }
    
    int num = q.front();
    q.pop();
    
    solve(q,n,k);
    
    q.push(num);
    
}

queue<int> modifyQueue(queue<int> q, int k) {
    int n = q.size();
    solve(q,n,k);
    
    for(int i = 0; i < n - k; i++){
        int num = q.front();
        q.pop();
        q.push(num);
    }
    
    return q;
}