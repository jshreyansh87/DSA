// Problem Statement => https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // checkEqual compares if two count array are equal or not
    bool checkEqual(int count1[26], int count2[26]){
        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        // count1 stores the count of chars in s1
        int count1[26] = {0};
        
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        int i = 0, windowSize = s1.length();
        // count2 stores the count of chars in s2 in current window
        int count2[26] = {0};
        
        // count chars of 1st window in s2
        while(i < windowSize && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        // check if permutation of s1 is substring of 1st window in s2
        if(checkEqual(count1, count2)){
            return true;
        }
        
        // shift the window by 1 unit in s2 and update the count array for s2 window
        while(i < s2.length()){
            int newIndex = s2[i] - 'a';
            count2[newIndex]++;
            
            int oldIndex = s2[i - windowSize] - 'a';
            count2[oldIndex]--;
            
            i++;
            
            // check if permutation of s1 is substring of current window in s2
            if(checkEqual(count1, count2)){
                return true;
            }
        }
        return false;
        
    }
};