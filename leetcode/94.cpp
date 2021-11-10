#include<iostream>
#include<queue>
#include<vector>

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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            
        }
        
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        vector<TreeNode*> ans;
        
        while(pendingnodes.size() != 0){
            TreeNode* front = pendingnodes.front();
            pendingnodes.pop();
            
            if(front->left != NULL){
                ans.push_back(front->left);
                pendingnodes.push(front->left);
            }
            ans.push_back(front);
            if(front->left != NULL){
                ans.push_back(front->right);
                pendingnodes.push(front->right);
            }            
        }
        vector<int> valans;
        int i = 0;
        while(ans[i] != NULL){
            valans.push_back(ans[i]->val);
            i++;
        }
        
        return valans;
    }
};