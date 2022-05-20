#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void helper(Node* root,vector<vector<int>>& vct){
        if(root == NULL){
            return;
        }
        
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(nullptr);
        
        while(pendingNodes.size() != 0){
            vector<int> temp;
            Node* front = pendingNodes.front();
            pendingNodes.pop();
            
            if(front == nullptr){
                vct.push_back(temp);
                if(pendingNodes.size() == 0){
                    break;
                }
                else{
                    pendingNodes.push(nullptr);
                }
            }
            else{
                temp.push_back(front->val);
                for(auto it: front->children){
                    pendingNodes.push(it);
                }
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vct;
        helper(root,vct);
        return vct;
    }
};

int main() {

}