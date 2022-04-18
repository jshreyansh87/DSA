// Problem Statement => https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root);
        
        return v[k-1];
    }
};