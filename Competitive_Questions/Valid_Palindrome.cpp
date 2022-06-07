// Problem Statement => https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp = "";
        
        for(int i = 0; i < s.size(); i++){
            if(iswalnum(s[i])){
                temp.push_back(s[i]);
            }
        }
        
        int st = 0, e = temp.size() - 1;
        
        if(st == e){
            return true;
        }
    
        while(st <= e){

            if(tolower(temp[st]) == tolower(temp[e])){
                st++; e--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};