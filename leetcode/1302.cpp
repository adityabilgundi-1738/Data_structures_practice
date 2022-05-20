#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
int height_of_tree(TreeNode* root){
    if (root == NULL)
        return 0;
    else{
        return max(height_of_tree(root->right),height_of_tree(root->left)) + 1;
    }
}
public:
    int deepestLeavesSum(TreeNode* root) {
        int height = height_of_tree(root);
        
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        int sum = 0;
        
        while(pendingnodes.size() != 0){
            TreeNode* temp = pendingnodes.front();
            pendingnodes.pop();
            if(temp != NULL){
                if(temp->left == NULL && temp->right == NULL){
                    sum += temp->val;
                }
                if(temp->left != NULL){
                    pendingnodes.push(temp->left);
                }
                if(temp->right != NULL){
                    pendingnodes.push(temp->right);
                }
            }
        }
    }
};

int main(){

    return 0;
}