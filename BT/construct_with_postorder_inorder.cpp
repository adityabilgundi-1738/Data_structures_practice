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

binaryTreeNode<int>* buildtreeHelper(int* in, int* po,int inS, int inE, int poS, int poE){
    if(inS > inE){
        return NULL;
    }
    int rootData = po[poE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPoS = poS;
    int lPoE = lInE - lInS + lPoS;
    int rPoS = lPoE + 1;
    int rPoE = poE - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root->left = buildtreeHelper(in,po,lInS,lInE,lPoS,lPoE);
    root->right = buildtreeHelper(in,po,rInS,rInE,rPoS,rPoE);

    return root;
}

binaryTreeNode<int>* buildtree(int* in ,int* po,int size){
    return buildtreeHelper(in,po,0,size-1,0,size-1);
}

int main(){
    //manual entry of inorder & postorder arrays
    int in[] = {4,2,8,5,9,1,6,3,7};
    int po[] = {4,8,9,5,2,6,7,3,1};

    binaryTreeNode<int>* root = buildtree(in,po,9);
    printer(root);
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    
    delete root;
    return 0;
}