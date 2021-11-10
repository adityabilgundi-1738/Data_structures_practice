#include<iostream>
#include"bintreenode.h"
#include<queue>
#include<climits>

using namespace std;

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

binaryTreeNode<int>* remove_leaves(binaryTreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        root = NULL;
        return root;
    }
    
    binaryTreeNode<int>* left = remove_leaves(root->left);
    binaryTreeNode<int>* right = remove_leaves(root->right);

    root->left = left;
    root->right = right;

    return root;
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    printer(root);
    cout<<endl;

    binaryTreeNode<int>* ans = remove_leaves(root);

    printer(ans);

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1  not a bst
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 bst
    return 0;
}