#include<iostream>
#include"tree_class.h"

using namespace std;

void treeprinter(treenode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<" "<<root->data<<":";
    for (int i = 0; i < root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    
    for (int i = 0; i < root->children.size(); i++){
        treeprinter(root->children[i]);
    }
}

treenode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    treenode<int>* root = new treenode<int>(rootdata);

    int n;
    cout<<"Enter the no of children"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        treenode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

int main(){
    // treenode<int>* root = new treenode<int>(1);
    // treenode<int>* node1 = new treenode<int>(4);
    // treenode<int>* node2 = new treenode<int>(5);
    // treenode<int>* node3 = new treenode<int>(6);
    // treenode<int>* node4 = new treenode<int>(12);

    treenode<int>* root = takeinput();

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);
    // node3->children.push_back(node4);

    treeprinter(root);

    return 0;
}