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

LLnode* bst_to_sortedll(binaryTreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }

    LLnode* left = bst_to_sortedll(root->left);
    LLnode* right = bst_to_sortedll(root->right);
    LLnode* roothead = new LLnode(root->data);

    LLnode* head = NULL;
    if(left == NULL && right == NULL){
        head = roothead;
    }
    else if(left == NULL){
        head = roothead;
        roothead->next = right;        
    }
    else if(right == NULL){
        head = left;
        LLnode* temp = left;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = roothead;
    }
    else{
        head = left;
        LLnode* temp = left;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = roothead;
        roothead->next = right;
    }
    return head;
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

    LLnode* head = bst_to_sortedll(root);

    cout<<endl<<"LL data : ";
    LLprinter(head);

    //5 3 8 1 4 7 9 -1 2 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 bst
    //3 1 5 -1 2 -1 -1 -1 -1 bst
    //5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1 not a  bst
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1  not a bst
    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 bst
    return 0;
}