// Problem Statement  =>   https://leetcode.com/problems/design-hashset/


#include <bits/stdc++.h>
using namespace std;

class BSTIterator {
public:
    vector <int> v;
    int i;
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        i = -1;
    }
    
    int next() {
        return v[++i];
    }
    
    bool hasNext() {
        if(i + 1 < v.size())
            return true;
        
        return false;
    }
    
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        
        inorder(root -> left);
        v.push_back(root -> val);
        inorder(root -> right);
    }
};