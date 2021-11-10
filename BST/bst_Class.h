#include<iostream>
#include"bintreenode.h"
#include<queue>

using namespace std;

class bst{
    private:
    binaryTreeNode<int>* root;

    public:
    bst(){
        root = NULL;
    }
    ~bst(){
        delete root;
    }
    private:bool hasdata(binaryTreeNode<int>* root,int data){
        if(root->data == data){
            return true;
        }
        else if(data > root->data){
            return hasdata(root->left,data);
        }
        else if(data < root->data){
            return hasdata(root->right,data);
        }
    }
    public:bool hasdata(int data){
        return hasdata(root,data);
    }

    private: binaryTreeNode<int>* insert(int data, binaryTreeNode<int>* root){
        if(root == NULL){
            binaryTreeNode<int>* newnode = new binaryTreeNode<int>(data);
            return newnode;
        }
        else if(data > root->data){
            root->right = insert(data,root->right);
        }
        else if(data < root->data){
            root->left = insert(data,root->left);
        }
        return root;
    }
    public:void insert(int data){
        root = insert(data,root);
    }

    private: binaryTreeNode<int>* deletenode(int data,binaryTreeNode<int>* root){
        if(root == NULL){
            return NULL;
        }
        else if(data > root->data){
            root->right = deletenode(data,root->right);
            return root;
        }
        else if(data < root->data){
            root->left = deletenode(data,root->left);
            return root;
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                binaryTreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right ==NULL){
                binaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else{
                binaryTreeNode<int>* minNode = root->right;
                while(minNode != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deletenode(rightMin,root->right);
                return root;
            }

        }
    }
    public: binaryTreeNode<int>* deletenode(int data){
        return deletenode(data,root);    
    }

    private: void printer(binaryTreeNode<int>* root){
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
    public:void printer(){
        printer(root);
    }
};
