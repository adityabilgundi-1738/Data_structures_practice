#include<iostream>
#include<climits>

template <typename T>

class stack{//any stack
    T* data;
    int nextindex;
    int capacity;
    
    public:
    stack(int num){//def constructor
        data = new T[num];
        nextindex = 0;
        capacity = num;
    }

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex == 0;
    }
    
    void push(T element){//add elements to the stack
        if(nextindex+1 == capacity){//resizing
            T* newdata = new T[2*capacity];//creating double cap arr
            for (int i = 0; i < capacity; i++){//copying to new
                newdata[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newdata;

            data[nextindex] = element;
            nextindex++;
            
        }
        else{
            data[nextindex] = element;
            nextindex++;
        }
    }
    
    T pop(){//delete element
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
            //in case of char
            //else
            // return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    T top(){//return top element
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;//in case of char
            //else
            // return INT_MIN;
        }
        return data[nextindex-1];

    }

};

int main(){
    stack <char> s(10);
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    //s.push(60);

    std::cout<<s.top()<<std::endl;

    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    
    std::cout<<s.size()<<std::endl;
    std::cout<<s.top()<<std::endl;
    
    std::cout<<s.isempty()<<std::endl;

    return 0;
}