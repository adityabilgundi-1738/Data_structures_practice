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

vector<int>* root_to_node_Path(binaryTreeNode<int>* root, int nodeData){//this function is for binary trees. works for all BT.
    if(root == NULL){
        return NULL;
    }

    if(root->data == nodeData){
        vector<int>* path = new vector<int>();
        path->push_back(root->data);
        return path;
    }

    vector<int>* left = root_to_node_Path(root->left,nodeData);
    if(left != NULL){
        left->push_back(root->data);
        return left;
    }

    vector<int>* right = root_to_node_Path(root->right,nodeData);
    if(right != NULL){
        right->push_back(root->data);
        return right;
    }
    else{
        return NULL;
    }

}

int main(){
    binaryTreeNode<int>* root = takeinput();


    int num;
    cout<<"Enter node data"<<endl;
    cin>>num;
    vector<int>* path = root_to_node_Path(root,num);

    for (int i = 0; i < path->size(); i++){//printing vector
        cout<<path->at(i)<<" ";
    }

    delete path;
    
    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    return 0;
}