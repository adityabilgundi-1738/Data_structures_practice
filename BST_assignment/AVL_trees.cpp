#include<iostream>
// #include"bintreenode.h"
using namespace std;

class avl{
    public:
    avl* left;
    avl* right;
    int data;
    int height;

    avl(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }

};

int height(avl* node){
    return node->height;
}

avl* rightRotate(avl* y){
    avl* x = y->left;
    avl* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    return x;
}

avl* leftRotate(avl* x){
    avl* y = x->right;
    avl* temp = y->left;

    y->left = x;
    x->right = temp;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    return y;
}

int getBalance(avl* node){
    if(node == NULL){
        return 0;
    }
    else
        return height(node->left) - height(node->right);
}

avl* insert(avl* node,int data){
    if(node == NULL){
        avl* node = new avl(data);
        return node;
    }
    if(data < node->data){
        node->left = insert(node->left,data);
    }
    else if(data > node->data){
        node->right = insert(node->right,data);
    }
    else{//duplicate nodes not allowed
        return node;
    }

    node->height = 1 + max(height(node->right),height(node->left));

    int balance = getBalance(node);

    if(balance > 1 && data < node->left->data){//LL rotation
        return rightRotate(node);
    }

    if(balance > 1 && data > node->left->data){//LR case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && data < node->right->data){//RR rotation
        return leftRotate(node);
    }

    if(balance > -1 && data > node->right->data){//RL case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
}

int main(){


    return 0;
}