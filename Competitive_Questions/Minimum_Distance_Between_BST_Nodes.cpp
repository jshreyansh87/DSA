// Problem Statement => https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> v;
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        
        inorder(root -> left);
        v.push_back(root -> val);
        inorder(root -> right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        
        int ans = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++){
            int curr_diff = v[i + 1] - v[i];
            if(curr_diff < ans){
                ans = curr_diff;
            }
        }
        
        return ans;
    }
};