// Problem Statement  =>   https://leetcode.com/problems/convert-bst-to-greater-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <TreeNode*> v;
    void soln(TreeNode* root){
        if(root == NULL)
            return;
        
        soln(root -> left);
        
        v.push_back(root);
        
        soln(root -> right);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root ==NULL)
            return root;
        
        soln(root);
        int sum = (*(v.rbegin())) -> val;
        // cout<<sum<<endl;
        for(int i=v.size()-2;i>=0;i--){

            sum += v[i] -> val;
            v[i] -> val = sum;
        }
        
        return root;
    }
};