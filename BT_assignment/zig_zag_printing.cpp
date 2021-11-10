#include<iostream>
#include"bintreenode.h"
using namespace std;
#include<queue>
#include<stack>

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

// void zigzagPrinter(binaryTreeNode<int>* root){//doesnt work (my attempt)
//     if(root == NULL){
//         return;
//     }
//     queue<binaryTreeNode<int>*> pendingnodes;
//     pendingnodes.push(root);
//     pendingnodes.push(NULL);
//     int i = 0;
//     int j = 0;
//     while(pendingnodes.size() != 0){
//         binaryTreeNode<int>* front;
//         if(j == 0){
//             front = pendingnodes.front();
//             j = 1;
//         } 
//         else
//             front = pendingnodes.back();
//         pendingnodes.pop();
//         if(front == NULL){
//             cout<<endl;
//             if(pendingnodes.size() == 0){
//                 break;
//             }
//             else{
//                 if(i == 0){
//                     reverseQueue(pendingnodes);
//                     i = 1;
//                 }
//                 if(i != 0){
//                     i = 0;
//                 }
//                 pendingnodes.push(NULL);
//             }
//         }
//         else{
//             cout<<front->data<<" ";
//             if(front->left != NULL){
//                 pendingnodes.push(front->left);
//             }
//             if(front->right != NULL){
//                 pendingnodes.push(front->right);
//             }
//         }
//     }
// }

void zizagtraversal(binaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }

    stack<binaryTreeNode<int>*> currentlevel;
    stack<binaryTreeNode<int>*> nextlevel;

    currentlevel.push(root);

    bool lefttoright = true;
    while(currentlevel.size() != 0){

        binaryTreeNode<int>* temp = currentlevel.top();
        currentlevel.pop();

        if(temp != NULL){
            cout << temp->data << " ";

            if(lefttoright) {
                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);
            }
            else{
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if(currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    zizagtraversal(root);
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    delete root;
    return 0;
}