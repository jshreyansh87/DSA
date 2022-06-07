// Problem Statement => https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // ansLen = length of final ans
        int ansLen = 0, i = 0, n = chars.size();
        
        while(i < n){
            int j = i + 1;
            // count number of duplicate chars placed together
            while(j < n && chars[i] == chars[j]){
                j++;
            }
            // enter the current char in the vector
            chars[ansLen++] = chars[i];
            // find the count of duplicate chars
            // i = first occurence of char
            // j = last occurence of char + 1
            int count = j - i;
            if(count > 1){
                // in case count is greater than 10, convert count to str
                string cnt = to_string(count);
                for(auto ch: cnt){
                    // insert count digit as a char in the vector
                    chars[ansLen++] = ch;
                }
            }
            // now i is the 1st occurence of new char
            i = j;
        }
        
        return ansLen;
    }
};