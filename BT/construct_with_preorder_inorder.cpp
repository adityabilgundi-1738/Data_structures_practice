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

binaryTreeNode<int>* buildtreeHelper(int* in, int* pr,int inS, int inE, int prS, int prE){
    if(inS > inE){
        return NULL;
    }

    int rootData = pr[prS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPrS = prS + 1;
    int lPrE = lInE - lInS + lPrS;
    int rPrS = lPrE + 1;
    int rPrE = prE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root->left = buildtreeHelper(in,pr,lInS,lInE,lPrS,lPrE);
    root->right = buildtreeHelper(in,pr,rInS,rInE,rPrS,rPrE);

    return root;
}

binaryTreeNode<int>* buildtree(int* in ,int* pr,int size){
    return buildtreeHelper(in,pr,0,size-1,0,size-1);
}

int main(){
    //manual entry of inorder & preorder arrays
    int in[] = {4,2,5,1,8,6,9,3,7};
    int pr[] = {1,2,4,5,3,6,8,9,7};

    binaryTreeNode<int>* root = buildtree(in,pr,9);
    printer(root);
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    
    delete root;
    return 0;
}