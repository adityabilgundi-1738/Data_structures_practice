#include<iostream>

using namespace std;

class node{
    public:
    int num;
    node* next;

    node(int num){
        this->num = num;
        next = NULL;
    }
};

node* takeinput(){
    int num;
    cin>>num;

    node* head = NULL;
    node* tail = NULL;

    while(num != -1){
        node* newnode = new node(num);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>num;
    }

    return head;
}

void printer(node* head){
    while(head != NULL){
        cout<<head->num<<" ";
        head = head->next;
    }
}

int index_return(node* head ,int n){//get index by recursion
    if(head->num == n){
        return 0;
    }
    else
        return 1 + index_return(head->next, n);

}

int main(){
    node* head = takeinput();
    printer(head);
    cout<<endl;

    cout<<"Enter the number whose index is needed"<<endl;
    int n;
    cin>>n;

    int index =index_return(head,n);
    cout<<"Index = "<<index<<endl;

    return 0;
}