#include<iostream>
#include"bintreenode.h"
#include<queue>
#include<climits>

using namespace std;

class LLnode{
    public:
    int num;
    LLnode* next;

    LLnode(int num){
        this->num = num;
        next = NULL;
    }
};

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

void bstprinter(binaryTreeNode<int>* root){
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

pair<LLnode*,LLnode*> bst_to_sortedll(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<LLnode*,LLnode*> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }

    pair<LLnode*,LLnode*> left = bst_to_sortedll(root->left);
    pair<LLnode*,LLnode*> right = bst_to_sortedll(root->right);
    LLnode* roothead = new LLnode(root->data);

    pair<LLnode*,LLnode*> ans;
        ans.first = NULL;
        ans.second = NULL;
    
    if(left.first == NULL && right.first == NULL){
        ans.first = roothead;
        ans.second = roothead;
    }
    else if(left.first == NULL){
        ans.first = roothead;
        roothead->next = right.first;
        right.second->next = NULL;    
        ans.second = right.second;  
    }
    else if(right.first == NULL){
        ans.first = left.first;
        left.second->next = roothead;
        ans.second = roothead;
    }
    else{
        ans.first = left.first;
        left.second->next = roothead;
        roothead->next = right.first;
        right.second->next = NULL;
        ans.second = right.second;
    }
    return ans;
}

void LLprinter(LLnode *head){
    LLnode *temp = head;
    while(temp!= NULL){
        cout<<temp->num<<" ";
        temp = temp->next; 
    }
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    pair<LLnode*,LLnode*> ans = bst_to_sortedll(root);

    cout<<endl<<"LL data : ";
    LLprinter(ans.first);

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1  not a bst
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 bst
    return 0;
}