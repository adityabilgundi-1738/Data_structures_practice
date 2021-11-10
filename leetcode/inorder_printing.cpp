#include<iostream>
#include"bintreenode.h"
using namespace std;
#include<queue>

binaryTreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;

    if(rootdata == -1){
        return NULL;
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootdata);
    queue<binaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size() != 0){
        binaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingnodes.push(child);
        }
        cout<<"Enter Right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}

void printer(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<binaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size() != 0){
        binaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<endl<<front->data<<": ";
        if(front->left != NULL){
            cout<<"L"<<front->left->data;
            pendingnodes.push(front->left);
        }

        if(front->right != NULL){
            cout<<"R"<<front->right->data;
            pendingnodes.push(front->right);
        }
    }
}

vector<int> inorderTraversal(binaryTreeNode<int>* root){
    if(root == NULL){
        vector<int> ans;
        return ans;
    }
        
        queue<binaryTreeNode<int>*> pendingnodes;
        pendingnodes.push(root);
        vector<binaryTreeNode<int>*> ans;
        
        while(pendingnodes.size() != 0){
            binaryTreeNode<int>* front = pendingnodes.front();
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
            valans.push_back(ans[i]->data);
            i++;
        }
        return valans;
    }

void inorderPrinter(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorderPrinter(root->left);
    cout<<root->data<<" ";
    inorderPrinter(root->right);
}

int main(){
    binaryTreeNode<int>* root = takeinput();
    
    //inorderPrinter(root);

    vector<int> inorder = inorderTraversal(root);
    int i = 0;
    while(inorder[i]){
        cout<<inorder[i]<<" ";
        i++;
    }
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    
    delete root;
    return 0;
}