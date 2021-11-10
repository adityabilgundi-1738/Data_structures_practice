#include<iostream>
#include"bintreenode.h"
using namespace std;
#include<queue>
#include<cstdlib>

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

pair<bool,int> check_balanced_2(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    //pair<check_balanced,height>

    pair<bool,int> a = check_balanced_2(root->left);
    pair<bool,int> b = check_balanced_2(root->right);

    if(abs(a.second - b.second) <=1){
        pair<bool,int> ans;
        ans.first = a.first && b.first;
        ans.second = max(a.second,b.second) + 1;
        return ans;
    }
    else{
        pair<bool,int> ans;
        ans.first = false;
        ans.second = max(a.second,b.second) + 1;
        return ans;
    }
}

bool helper_balanced(binaryTreeNode<int>* root){
    pair<bool,int> ans = check_balanced_2(root);
    return ans.first;
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    //printer(root);

    bool ans = helper_balanced(root);
    cout<<"balanced? -> "<<ans<<endl;
    
    /* without helper */
        
    // pair<bool,int> ans = check_balanced_2(root);
    // cout<<"Answer: the tree is balanced ? -> "<<ans.first<<endl;
    // cout<<"Height of tree: "<<ans.second<<endl;
    
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    delete root;
    return 0;
}