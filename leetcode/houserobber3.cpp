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
    pair<int,int> helper(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return make_pair(0,0);
        }
        //pair = {with_root, without_root}
        pair<int,int> l,r;
        if(root->left != NULL) l = helper(root->left);
        if(root->right != NULL) r = helper(root->right);

        int with_root = l.second + r.second + root->val;
        int without_root = max(l.first,l.second) + max(r.first,r.second);
        
        return make_pair(with_root,without_root);
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first,ans.second);
    }
};

int main(){

    return 0;
}