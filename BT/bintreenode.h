#include<iostream>
using namespace std;

template <typename T>

class binaryTreeNode{
    public:

    T data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
