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

class bstclass{
    public:
    bool check_bst;
    int max;
    int min;
};

bstclass check_bst_max_min(binaryTreeNode<int>* root){//leaf to root traversal && O(n)
    if(root == NULL){
        bstclass p;
        p.check_bst = true;
        p.max = INT_MIN;
        p.min = INT_MAX;

        return p;
    }
    
    bstclass left = check_bst_max_min(root->left);
    bstclass right = check_bst_max_min(root->right);

    bstclass ans;
    
    ans.max = max(right.max,max(left.max,root->data));
    ans.min = min(right.min,min(left.min,root->data));
    ans.check_bst = (root->data > left.max) && (root->data <= right.min) && (right.check_bst) && (left.check_bst);

    return ans;    
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    //printer(root);

    bool ans = check_bst_max_min(root).check_bst;
    cout<<ans<<endl;

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    return 0;
}