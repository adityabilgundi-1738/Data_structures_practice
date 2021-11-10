#include<iostream>
#include"bintreenode.h"
#include<queue>
#include<climits>

using namespace std;

//given input a BT print the height of the largest BST.

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

class helperclass{
    public:
    int max;
    int min;
    bool isBST;
    int height;

    helperclass(){
        max = 0;
        min = 0;
        height = 0;
        isBST = true;
    }
};

helperclass largest_bst(binaryTreeNode<int>* root){
    if(root == NULL){
        helperclass ans;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.height = 0;
        ans.isBST = true;

        return ans;
    }
    helperclass left = largest_bst(root->left);
    helperclass right = largest_bst(root->right);
    helperclass ans;

    if(left.isBST == true && right.isBST == true && (root->data > left.max) && (root->data < right.min)){
        ans.max = max(right.max,max(left.max,root->data));
        ans.min = min(right.min,min(left.min,root->data));
        ans.height = max(left.height,right.height) + 1; 
        ans.isBST = true;
    }
    else if(left.isBST == false || right.isBST == false){
        ans.max = right.max;
        ans.min = left.min;
        ans.height = max(left.height,right.height);
        ans.isBST = false;
    }
    return ans;
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    helperclass ans = largest_bst(root);
    cout<<endl;
    cout<<"Height :"<<ans.height<<endl;
    cout<<"MAX in tree "<<ans.max<<endl;
    cout<<"MIN in tree "<<ans.min<<endl;

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst 
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1  not a bst
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 bst
    return 0;
}