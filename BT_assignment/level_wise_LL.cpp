#include<iostream>
#include"bintreenode.h"
using namespace std;
#include<queue>

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

class LLnode{
    public:
    int num;
    LLnode* next;

    LLnode(int num){//default constructor
        this -> num = num;
        next = NULL;
    }
};

void LLprinter(LLnode *head){
    LLnode *temp = head; 
    while(temp!= NULL){
        cout<<temp->num<<" ";
        temp = temp->next; 
    }
}

vector<LLnode*> levelWiseLL(binaryTreeNode<int>* root){
    if(root == NULL){
        cout<<"Empty Tree"<<endl;

        LLnode* node = new LLnode(0);
        vector<LLnode*> ans;
        ans.push_back(node);
        
        return ans;
    }

    vector<LLnode*> ans;
    LLnode* head = NULL;
    LLnode* tail = NULL;

    queue<binaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);

    while(pendingnodes.size() != 0){
        binaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        if(front != NULL){
            LLnode* n = new LLnode(front->data);
            if(head == NULL){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
            if(front->left != NULL){
                pendingnodes.push(front->left);
            }
            if(front->right != NULL){
                pendingnodes.push(front->right);
            }
        }
        else{
            ans.push_back(head);
            head = NULL;
            tail = NULL;

            if(pendingnodes.size() == 0){
                break;
            }
            else
            pendingnodes.push(NULL);
        }
    
    }
    return ans;
}

int main(){
    binaryTreeNode<int>* root = takeinput();

    vector<LLnode*> ans = levelWiseLL(root);
    int i = 0;
    while(ans[i] != NULL){
        LLprinter(ans[i]);
        cout<<endl;
        ++i;
    }
    
    //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 7 8 -1 -1 -1
    //5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    
    delete root;
    return 0;
}