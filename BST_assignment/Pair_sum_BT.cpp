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

bool search(binaryTreeNode<int>* root,int num){
    if(root == NULL){
        return false;
    }
    if(root->data == num){
        root->data = INT_MIN;
        return true;
    }
    else{
        return search(root->left,num) || search(root->right,num);
    }
}

void printPairs(int sum,binaryTreeNode<int>* root,binaryTreeNode<int>* Mainroot){
    if(root == NULL){
        return;
    }

    if(root->data != INT_MIN){
        pair<int,int> sumPair;
        sumPair.first = root->data;
        int temp = root->data;
        root->data = INT_MIN;

        int numNeeded = sum - sumPair.first;
        bool found = search(Mainroot,numNeeded) || search(Mainroot,numNeeded);
        root->data = temp;

        if(found){
            sumPair.second = numNeeded;
            root->data = INT_MIN;
            cout<<sumPair.first<<"+"<<sumPair.second<<endl;
        }
    }
    printPairs(sum,root->left,Mainroot);
    printPairs(sum,root->right,Mainroot);
    return;
}

int main(){
    binaryTreeNode<int>* root = takeinput();
    
    int sum;
    cout<<"Enter Sum needed"<<endl;
    cin>>sum;

    printPairs(sum,root,root);


    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 14 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}