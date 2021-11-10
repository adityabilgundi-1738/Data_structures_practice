#include<iostream>

using namespace std;

class dynamicarr{
    private:
    
    int *arr;
    int capacity;
    int index;

    public:
    
    dynamicarr(){//constructor
        arr = new int[5];
        capacity = 5;
        index = 0; 
    }
    
    void addele(int element){//adding elements
        if(capacity == index){
            int *newarr;
            newarr = new int[capacity*2];

            for (int i = 0; i < capacity; i++){
                newarr[i] = arr[i];
            }
            delete arr;
            arr = newarr;
            capacity *=2;
        }
        
        arr[index] = element;
        index++;
    }

    dynamicarr(dynamicarr const &d){//custom copy constructor bcs the inbuilt copy constructor always performs shallow copy
        //shallow copy
        //this -> arr = d.arr;
        //deep copy
        this -> arr = new int[d.capacity];
        for (int i = 0; i < d.index; i++){
            this -> arr[i] = d.arr[i];
        }

        this ->capacity = d.capacity;
        this ->index = d.index;
    }

    int getele(int i) const {//printing particular index element
        if(i < index){
            return arr[i];
        }
        else
        return -1; //returning -1 or any other int other than 0, means that the fucntion was not successful
    }

    void addparti(int i, int val){//adding element at a particular index
        if(i<index)
            arr[i] = val;
        else if(index == i)
            addele(val);
        else 
            return;
    }

    dynamicarr operator = (dynamicarr e){//overloaded '=' operator
        this -> arr = new int[e.capacity];
        for (int i = 0; i < e.index; i++){
            this -> arr[i] = e.arr[i];
        }

        this ->capacity = e.capacity;
        this ->index = e.index;
    }

    void printer () const {//prints all elements
        for (int i = 0; i < index; i++){
            cout<<arr[i]<<" ";
        }
        
    }

};

int main(){

    dynamicarr a;
    //adding elements
    a.addele(1);
    a.addele(2);
    a.addele(3);
    a.addele(4);
    a.addele(5);
    a.addele(6);

    //printing elements
    a.printer();
    cout<<endl;

    dynamicarr d(a); //copy constructor called
    a.addparti(0,1000);
    d.printer();

    a.getele(7);

    dynamicarr e = a;//overloaded operator '=' called
    e.printer();

    return 0;
}