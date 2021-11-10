#include<iostream>

using namespace std;

class node{
    public:
    node* next;
    int num;

    node(int num){
        next = NULL;
        this->num = num;
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

int search(node* head, int n){//search by iteration
    node* temp = head;
    int index = 0;

    while(temp->num != n){
        index++;
        temp = temp->next;
    }
    return index;
}

int searchrecur(node* head, int n){//search by recursion
    if(head->num == n){
        return 0;
    }
    else{
        return 1 + searchrecur(head->next, n);
    }
}

int main(){
    node* head = takeinput();

    //printer(head);

    int number;

    cout<<"Enter element to be searched"<<endl;
    cin>>number;

    //int index = search(head,number);
    //cout<<endl<<"Index of "<<number<<" is "<<index;

    int index = searchrecur(head,number);
    cout<<endl<<"Index of "<<number<<" is "<<index;

    return 0;
}