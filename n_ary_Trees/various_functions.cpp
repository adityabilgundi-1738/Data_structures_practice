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

int nodes_count(treenode<int>* root){
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++){
        ans += nodes_count(root->children[i]);
    }
    return ans;
}

int sumnodes(treenode<int>* root){
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++){
        ans += sumnodes(root->children[i]);
    }
    return ans;
}

int maxvalue(treenode<int>* root){
    if(root->children.size() == 0){
        return root->data;
    }
    int largest = root->data;
    for (int i = 0; i < root->children.size(); i++){
        int a = maxvalue(root->children[i]);
        if(a > largest){
            largest = a;
        }
        // maxvalue(root->children[i]);
    }
    return largest;
}

void print_levelk(treenode<int>* root, int k){
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    if(root == NULL){
        return;
    }
    for (int i = 0; i < root->children.size(); i++){
        print_levelk(root->children[i],k-1);
    }
    
}

int countleafnodes(treenode<int>* root,int num){
    if(root->children.size() == 0){
        return 1;
    }
    else{
        for (int i = 0; i < root->children.size(); i++){
            num += countleafnodes(root->children[i],num);
        }
        return num-1;
    }

}

int main(){
    treenode<int>* a = takeinput();

    treeprinter(a);
    cout<<"Total no of nodes = "<<nodes_count(a)<<endl;
    cout<<"sum of node data = "<<sumnodes(a)<<endl;

    print_levelk(a,3);

    int b = 0;
    cout<<countleafnodes(a,b)<<endl;

    cout<<"Maximum value :"<<maxvalue(a)<<endl;

    return 0;
}