#include<iostream>
#include"bintreenode.h"
#include<queue>
#include<climits>

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

int maximum(binaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }

    int left = maximum(root->left);
    int right = maximum(root->right);

    int ans = max(left,max(root->data,right));

    return ans;
}

int minimum(binaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    int left = minimum(root->left);
    int right = minimum(root->right);

    int ans = min(left,min(root->data,right));

    return ans;
}

bool check_bst(binaryTreeNode<int>* root){//leaf to root traversal && O(n*h) min = O(nlogn) max = O(n^2)
    if(root == NULL){
        return true;
    }

    if(root->data < maximum(root->left) || root->data >= minimum(root->right)){
        return false;
    }
    else{
        return (check_bst(root->right) && check_bst(root->left));
    }
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    printer(root);
    cout<<endl;
    cout<<endl;

    bool ans = check_bst(root);
    cout<<ans<<endl;

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    return 0;
}