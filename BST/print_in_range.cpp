#include<iostream>
#include"bintreenode.h"
#include<queue>

using namespace std;

//level wise takeinput & printer
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

void print_range(binaryTreeNode<int>* root, int left, int right){
    if(root == NULL){
        return;
    }

    if(root->data > left){
        print_range(root->left,left,right);
    }
    if(root->data <= right && root->data >= left){
        cout<<root->data<<" "; 
    }
    if(root->data < right){
        print_range(root->right,left,right);
    }
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    printer(root);
    cout<<endl<<endl;

    cout<<"Printer in range"<<endl;

    int left,right;
    cout<<endl;
    cout<<"Enter left limit"<<endl;
    cin>>left;
    cout<<"Enter right limit"<<endl;
    cin>>right;

    print_range(root,left,right);

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1

    return 0;
}