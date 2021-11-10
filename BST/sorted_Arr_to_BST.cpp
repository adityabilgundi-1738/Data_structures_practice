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

bool check_bst(binaryTreeNode<int>* root,int min = INT_MIN, int max = INT_MAX){//root to leaf traversal O(n)
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }
    else{
        return (check_bst(root->left,min,root->data-1) && check_bst(root->right,root->data,max));
    }
}

binaryTreeNode<int>* constructbst(int arr[],int start,int end){
    if(start > end){
        return NULL;
    }

    int mid = (start+end+1)/2;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(arr[mid]);
    root->left = constructbst(arr,start,mid-1);
    root->right = constructbst(arr,mid+1,end);

    return root;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};//sorted array
    int n = sizeof(arr)/sizeof(arr[0]);
    binaryTreeNode<int>* root = constructbst(arr,0,n-1);
    printer(root);

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1  not a bst
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 bst
    return 0;
}