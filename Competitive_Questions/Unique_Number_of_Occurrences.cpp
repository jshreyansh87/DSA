// Problem Statement => https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int, int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }

        set <int> st;
        
        for(auto i: mp){
            st.insert(i.second);
        }
        
        if(mp.size() == st.size()){
            return true;
        }
        
        
        return false;
    }
};