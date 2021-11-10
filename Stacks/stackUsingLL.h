//first header file
using namespace std;
template <typename T>

class node{
    public:

    T num;

    node<T>* next;// !!!!!!!!!!!!!!  IMPORANT !!!!!!!!!!!!!!!
    
    node(T num){
        this->num = num;
        next = NULL;
    }
};

template <typename T>//should mention this line individually for each class

class stack{
    public:
    node<T>* top;

    stack(){//def constructor
        top = NULL;
    }

    node<T>* push(T num){
        node<T>* temp = new node<T>(num);
        if(top == NULL){
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
            temp = NULL;
            delete [] temp;
        }
        return top;
    }

    T first(){//returns top of Stack
        return top->num;
    }

    T pop(){//removes Top elements
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        node<T>* temp = top;
        top = top->next;
        T n =  temp->num;
        delete [] temp;// deleteing is important
        return n;
    }
    
    int size(){//returns size
        node<T>* temp = top;
        if(temp == NULL){
            return 0;
        }
        int count = 1;
        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool isempty(){
        return top == NULL;
    }
};
