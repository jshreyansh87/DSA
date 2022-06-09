// Problem Statement => https://leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        
        // applying Sieve of Eratosthenes
        int count = 0;
        
        // make an array or vector till n and assume all the number to be prime
        vector <bool> isprime(n + 1, true);
        
        // numbers 0 and 1 are marked non primes
        isprime[0] = isprime[1] = false;
        
        for(int i = 2; i < n; i++){
            // if the curr number is prime
            if(isprime[i]){
                // then increment the count
                count++;
                
                // and mark all the multiples of this prime as false
                for(int j = i * 2; j < n; j += i){
                    isprime[j] = false;
                }
            }
        }
        
        return count;
    }
};