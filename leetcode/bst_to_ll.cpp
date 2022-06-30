#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* curr;
    void preorderHelper(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(curr == NULL){
            TreeNode* newNode = new TreeNode(root->val);
            curr = newNode;
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
        else{
            TreeNode* newNode = new TreeNode(root->val);
            curr->right = newNode;
            curr = newNode;
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
    }
public:
    void flatten(TreeNode* root){
        preorderHelper(root);
        root = curr;
        return;
    }
};

int main(){

    return 0;
}