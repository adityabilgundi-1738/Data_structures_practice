#include<iostream>
#include"bintreenode.h"
using namespace std;

void printer(binaryTreeNode<int>* root){//doesn't print level wise
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printer(root->left);
    printer(root->right);
}

binaryTreeNode<int>* takeinput(){//doesn't take input level wise
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;

    if(rootdata == -1){
        return NULL;
    }
    
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootdata);
    binaryTreeNode<int>* leftchild = takeinput();
    binaryTreeNode<int>* rightchild = takeinput();

    root->left = leftchild;
    root->right = rightchild;

    return root;
}

int main(){
    // binaryTreeNode<int>* root = new binaryTreeNode<int>(1);
    // binaryTreeNode<int>* node1 = new binaryTreeNode<int>(2);
    // binaryTreeNode<int>* node2 = new binaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    binaryTreeNode<int>* root = takeinput();

    printer(root);
    delete root;
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    return 0;
}