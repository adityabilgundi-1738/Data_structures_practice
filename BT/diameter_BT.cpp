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

//the time complexity of the combined height & diameter 
//funcitons turns out to be n*h 
//with a min case of n*log(n) & max case of n*n

int height(binaryTreeNode<int>* root)
{
    if (root == NULL)
        return 0;
    else{
        return max(height(root->right),height(root->left)) + 1;
    }
}

int diameter(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1,max(option2,option3));
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    cout<<"Diameter of Tree = "<<diameter(root)<<endl;
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    delete root;
    return 0;
}