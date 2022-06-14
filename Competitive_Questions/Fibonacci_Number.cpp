// Problem Statement  =>   https://leetcode.com/problems/fibonacci-number/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // base case
        if(n == 0 || n == 1){
            return n;
        }
        
        return fib(n - 1) + fib(n - 2);
    }
};