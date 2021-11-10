#include<iostream>
#include"tree_class.h"
#include<queue>

using namespace std;

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
        cout<<front<<":";
        for (int i = 0; i < front->children.size(); i++){
            cout<<front->children[i]<<",";
        }
        for (int i = 0; i < front->children.size(); i++){
            pendingnodes.push(front->children[i]);
        }
    }
}

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

int check_presence(treenode<int>* root ,int num,int ans){
    if(root->data == num){
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++){
        ans+=check_presence(root->children[i],num,ans);
    }
    
    return ans;
}

int main(){
    treenode<int>* a = takeinput();
    int b = 0;
    cout<<"Answer: "<<check_presence(a,11,b)-1<<endl;
    //1 3 2 3 4 3 5 6 7 1 8 2 9 10 0 0 0 0 1 11 0 1 12 0

    return 0;
}