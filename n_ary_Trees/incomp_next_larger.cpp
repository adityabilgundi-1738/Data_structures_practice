#include<iostream>
#include"tree_class.h"
#include<queue>

using namespace std;
//Given a generic tree and an integer n. Find and return the node with next larger element in the tree

treenode<int>* takeinput(){
    cout<<"Enter the root data"<<endl;
    int rootdata;
    cin>>rootdata;
    treenode<int>* root = new treenode<int>(rootdata);

    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size() != 0){
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter the number of children of "<<front->data<<endl;
        int children;
        cin>>children;
        for (int i = 0; i < children; i++){
            int child_data;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>child_data;
            treenode<int>* child = new treenode<int>(child_data);
            front->children.push_back(child);
            pendingnodes.push(child);
        }        
    }
    return root;
}

void treeprinter(treenode<int>* root){
    if(root == NULL){
        cout<<"Empty Tree"<<endl;
        return;
    }
    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<" "<<front->data<<":";
        for (int i = 0; i < front->children.size(); i++){
            cout<<front->children[i]->data<<",";
        }
        for (int i = 0; i < front->children.size(); i++){
            pendingnodes.push(front->children[i]);
        }
    }
}

// treenode<int>* nextlarger(treenode<int>* root,int num){//logic is correct but doesnt work
//     treenode<int>* ansnode;
//     if(root->data > num){
//         ansnode = root;
//     }
//     else{
//         ansnode = NULL;
//     }
//     for (int i = 0; i < root->children.size(); i++){
//         treenode<int>* temp = nextlarger(root->children[i],num);
//         if(ansnode == NULL){
//             ansnode = temp;
//         }
//         if(temp->data < ansnode->data){
//             ansnode = temp;
//         }
//     }
//     return ansnode;
// }

// int nextlarger(treenode<int>* root,int num){//logic is correct but doesnt work
//     int ansnode;
//     if(root->data > num){
//         ansnode = root->data;
//     }
//     else{
//         ansnode = 0;
//     }
//     for (int i = 0; i < root->children.size(); i++){
//         int temp = nextlarger(root->children[i],num);
//         if(ansnode == 0){
//             ansnode = temp;
//         }
//         if(temp < ansnode){
//             ansnode = temp;
//         }
//     }
//     return ansnode;
// }

int main(){

    treenode<int>* a = takeinput();

    //cout<<nextlarger(a,12)<<endl;
    //10 3 5 6 12 2 9 8 2 100 3 0 0 0 0 0
    return 0;
}