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

bool check_identical(treenode<int>* root1, treenode<int>* root2){
    if(root1->data != root2->data){
        return false;
    }
    else if(root1->children.size() != root2->children.size()){
        return false;
    }
    else if(root1->children.size() != 0){
        for (int i = 0; i < root1->children.size() ; i++){
            if(i == root1->children.size() && check_identical(root1->children[i],root2->children[i]) == true){
                return true;
            }
            else if(check_identical(root1->children[i],root2->children[i]) == true){
                continue;
            }
            else if(check_identical(root1->children[i],root2->children[i]) == false){
                return false;
            }
        }
    }
    else return true;
}

int main(){
    cout<<"First tree: "<<endl;
    treenode<int>* root1 = takeinput();
    cout<<"Second tree: "<<endl;
    treenode<int>* root2 = takeinput();
    
    bool answer = true;
    answer = check_identical(root1,root2);
    
    if(answer != false){
        cout<<"identical Trees"<<endl;
    }
    else
    cout<<"Two trees are not identical"<<endl;
    

    //1 3 2 3 4 3 5 6 7 1 8 2 9 10 0 0 0 0 1 11 0 1 12 0
    //1 3 2 3 4 3 5 6 7 1 8 2 9 10 0 0 0 0 1 11 0 1 13 0
    //1 3 2 3 4 0 1 6 1 5 0 0
    //1 3 2 5 4 0 1 6 1 5 0 0

    return 0;
}