// Problem Statement => https://leetcode.com/problems/increasing-order-search-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <TreeNode*> v;
    
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        
        inorder(root -> left);
        
        v.push_back(root);
        
        inorder(root -> right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return root;
        
        TreeNode* ans = new TreeNode(0);
        TreeNode* currNode = ans;
        
        inorder(root);
        
        for(int i = 0; i < v.size(); i++){
            currNode -> right = new TreeNode(v[i] -> val);
            currNode = currNode -> right;
        }
        
        return ans -> right;
    }
};