#include<iostream>

using namespace std;

//this code has time complexity of n
class node{
    public:
    int num;
    node* next;

    node(int num){//default constructor
        this -> num = num;
        next = NULL;
    }

};

void printer(node *head){
    node *temp = head; 
    while(temp!= NULL){
        cout<<temp->num<<" ";
        temp = temp->next; 
    }
}

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
            tail -> next = newnode;
            tail = newnode;
        }
        cin>>num;
    }
    return head;
}

node* insertnode(node* head, int i, int num){
    node* newnode = new node(num);

    node* temp = head;
    int count = 0;
    
    if(i ==0){//special case for 0
        newnode -> next = head;
        head = newnode;
        return head;
    }
    
    while((temp !=NULL) && (count < i-1)){//the condition (temp !=NULL) makes sure that NULL -> next doesnt occour (segmentation fault)
        temp = temp ->next;
        count++;
    }
    if(temp != NULL){//preventing running these lines if NULL
        newnode->next = temp -> next;
        temp->next = newnode;
    }
    else if(temp == NULL){
        cout<<endl;
        cout<<"Segmentation Fault"<<endl;
        cout<<"jk, index value is more than the max index of the LL"<<endl;

    }
    return head;
}

node* deletenode(node* head, int i){
    node*temp = head;
    int count = 0;
    
    if(i == 0){
        head = temp ->next;
        return head;
    }

    while((temp != NULL) && (count < i-1)){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        node* a = temp;
        temp = temp -> next;
        a->next = temp->next;
        delete temp;
    }
    else if(temp == NULL){
        cout<<endl;
        cout<<"Segmentation Fault"<<endl;
        cout<<"Index value is more than the max index of the LL"<<endl;
    }
    return head;

}

int no_of_nodes(node* head){//length of linked list by iteration
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int get_nodes(node* head){//length of linked list by recursion
    node* temp = head;

    if(temp == NULL){
        return 0;
    }

    else
    return 1+get_nodes(head->next);
}

int main(){
    node* head  = takeinput();
    
    //syntax : head = insertnode(head,index,value); 
    // head = insertnode(head,20,69);
    // head = insertnode(head,0,123);//works

    head = deletenode(head,0);
    //printer(head);

    cout<<no_of_nodes(head)<<endl;//iterative
    cout<<get_nodes(head)<<endl;//recursive
    
    return 0;
}