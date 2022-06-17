// Problem Statement => https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digits, string output, int index, string mapping[], vector <string>& ans){
        // approach => run an index in the string and for each element find the mapping of combination
        //              for each char in combination push it in the output
        //              and recursiely call this function again
        //              after recursive call pop the char pushed in output earlier
        //              so that the next char can be pushed in this for loop
        
        
        // base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        // find the number
        int element = digits[index] - '0';
        // find the combination against this number
        string comb = mapping[element];
        
        // for each char in combination
        for(int i = 0; i < comb.length(); i++){
            // add this char in output
            output.push_back(comb[i]);
            // recursive call
            solve(digits, output, index + 1, mapping, ans);
            // pop this char from output
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0){
            return {};
        }
        
        vector <string> ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, index, mapping, ans);
        
        return ans;
    }
};