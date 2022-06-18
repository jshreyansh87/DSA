// Problem Statement => https://www.codingninjas.com/codestudio/problems/permutations-of-a-string_985254?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool my_compare(string a, string b){
    if(a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0){
        return a.size() > b.size();
    }
    else{
        return a < b;
    }
}

void solve(string str, vector <string> &ans, int index){
    // base case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }
    
    for(int i = index; i < str.length(); i++){
        swap(str[i], str[index]);
        solve(str, ans, index + 1);
        swap(str[i], str[index]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector <string> ans;
    int index = 0;
    
    solve(str, ans, index);
    sort(ans.begin(), ans.end());
    return ans;
}