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

class toptwo{
    public:
    int maxi;
    int secmax;

    toptwo(){
        maxi = 0;
        secmax = 0;
    }
};

toptwo seclargest(treenode<int>* root){//works perfectly
    toptwo ans;
    if(ans.maxi == 0){
        ans.maxi = root->data;
        ans.secmax = 0;
    }
    for (int i = 0; i < root->children.size(); i++){
        toptwo temp = seclargest(root->children[i]);
        
        if(temp.maxi > ans.maxi){
            toptwo temp2;
            temp2.maxi = ans.maxi;
            ans.maxi = temp.maxi;
            
            if(ans.secmax == 0){
                ans.secmax = temp.secmax > temp2.maxi ? temp.secmax : temp2.maxi;
            }
            else{
                ans.secmax = temp2.maxi > ans.secmax ? temp2.maxi : ans.secmax;
                ans.secmax = temp.secmax > ans.secmax ? temp.secmax : ans.secmax;
            }
        }
        else if(temp.maxi > ans.secmax || ans.secmax == 0){
            ans.secmax = temp.maxi;
        }
        else continue;
    }
    return ans;
}

int main(){

    treenode<int>* a = takeinput();

    toptwo ans;
    ans = seclargest(a);

    //cout<<ans.maxi<<endl;
    cout<<ans.secmax<<endl;

    //10 3 5 6 12 2 9 8 2 100 3 0 0 0 0 0 = 12
    //1 3 2 3 4 3 5 6 7 1 8 2 9 10 0 0 0 0 1 11 0 1 12 0 = 11
    return 0;
}