#include<iostream>
#include"tree_class.h"
#include<queue>

using namespace std;

treenode<int>* takeinputLevelWise(){
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    treenode<int>* root = new treenode<int>(rootdata);

    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    
    while(pendingnodes.size() != 0){//pendingnodes.empty() returns 1 if it is empty
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter num of children of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for (int i = 0; i < numchild; i++){
            int childdata;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            treenode<int>* child = new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

int main(){

    treenode<int>* root = takeinputLevelWise();

    return 0;
}