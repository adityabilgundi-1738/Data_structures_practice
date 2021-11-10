#include<iostream>
#include"tree_class.h"
#include<queue>

using namespace std;

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

treenode<int>* maxo = NULL;

void findlargest(treenode<int>* root)
{
    if (root == NULL)
        return;
    if(maxo == NULL){
        maxo = root;
    }
    else if (root->data > maxo->data) {
        maxo = root;
    }

    for (int i = 0;i < root->children.size(); i++) {
        findlargest(root->children[i]);
    }
}

treenode<int>* mino = NULL;

void findsmallest(treenode<int>* root)
{
    if (root == NULL)
        return;
    if(mino == NULL){
        mino = root;
    }
    else if (root->data < mino->data) {
        mino = root;
    }

    for (int i = 0;i < root->children.size(); i++) {
        findsmallest(root->children[i]);
    }
}

int main(){

    treenode<int>* a = takeinput();

    findlargest(a);
    cout<<maxo->data<<endl;

    findsmallest(a);
    cout<<mino->data<<endl;

    //10 3 5 6 12 2 9 8 2 100 3 0 0 0 0 0
    return 0;
}