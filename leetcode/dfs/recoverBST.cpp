#include<iostream>
using namespace std;

class Solution {
private:
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        helper(root->left);
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
    }
};