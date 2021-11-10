#include<iostream>

using namespace std;

class complex{
    int a,b;

    public:
    //creating a constructor
    //it is a special memmber function with the same name of the class
    //it is used to initialise the members of the class
    complex(void); //constructor declaration
    //constructor doesnt have a return type
    //it gets called automatically

    void printdata(){
        cout<<a<<" +i"<<b<<endl;
    }
};

complex :: complex(void){
    cout<<"Enter the values"<<endl;
    cin>>a;
    cin>>b;
}

int main(){
    complex c;
    //if the name of the func was different then 
    //there would be an extra line
    c.printdata();
    // if the name of the function in the class was different from 
    //the name of the class then, this wouls'nt work

    return 0;
} 

/*  Characteristics of Constructors

1. It should be declared in the public section of the class 
2. They are automatically invoked whenever the object is created 
3. They cannot return values and do not have return types
4. It can have default arguments 
5. We cannot refer to their address

*/