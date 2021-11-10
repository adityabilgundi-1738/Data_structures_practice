#include<iostream>

using namespace std;

class polyno{
    private:
    int *degarr;
    int capacity;

    public:
    
    //constructors
    
    polyno(){//default constructor
        degarr = new int[10];
        capacity = 10;
        for (int i = 0; i < capacity; i++){
            degarr[i] = 0;
        }
    }

    polyno (polyno const &d){//copy constructor
        this -> degarr = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++){
            this -> degarr[i] = d.degarr[i];
        }
        this -> capacity = d.capacity;
    } 
    
    //setters and getters

    void setcoeff(int degree, int coeff){//overrides the previous values with their coefficients
        while(degree >= capacity){
            if(degree >= capacity){
            
            int *newdegarr;
            
            newdegarr = new int[capacity*2];
            
            for (int i = 0; i < capacity*2; i++){//clearing of garbage
                newdegarr[i] = 0;
            }
            
            for (int i = 0; i < capacity; i++){//hard copying values
                newdegarr[i] = degarr[i];
            }
            delete degarr;
            degarr = newdegarr;
            capacity *=2;
            }
        }
        degarr[degree] = coeff;
    }
    
    void printer(){//prints values in the form of coefficient * varaible * index 
        for (int i = 0; i < capacity; i++){
            if (degarr[i] != 0){
                cout<<degarr[i]<<"x"<<i<<" + ";
            }
        }
    } 
    
    //overlaoded operators
    
    polyno operator +(polyno f){//overlaoded '+' operator
        if(f.capacity > this->capacity){
            int *newdegarr;
            newdegarr = new int[(this->capacity)*2];
            
            for (int i = 0; i < (this->capacity)*2; i++){//clearing of garbage
                newdegarr[i] = 0;
            }

            for (int i = 0; i < this -> capacity; i++){
                newdegarr[i] = this -> degarr[i];
            }
            delete degarr;
            degarr = newdegarr;
            (this -> capacity) *=2; 
        }

        for (int i = 0; i < capacity; i++){
            this -> degarr[i] += f.degarr[i];
        }
        
        return *this;
    }
    
    polyno operator -(polyno f){//overlaoded '-' operator
        if(f.capacity > this->capacity){
            int *newdegarr;
            newdegarr = new int[(this->capacity)*2];
            
            for (int i = 0; i < (this->capacity)*2; i++){//clearing of garbage
                newdegarr[i] = 0;
            }

            for (int i = 0; i < this -> capacity; i++){
                newdegarr[i] = this -> degarr[i];
            }
            delete degarr;
            degarr = newdegarr;
            (this -> capacity) *=2;
            
        }

        for (int i = 0; i < capacity; i++){
            this -> degarr[i] -= f.degarr[i];
        }

        return *this;
    }
    
    polyno operator *(polyno f){//overlaoded '*' operator
        int *prod = new int[capacity+f.capacity +1];

        for (int i = 0; i < capacity+f.capacity +1; i++){//clearing garbage
            prod[i] = 0;
        }
        
        for (int i = 0; i < capacity; i++){
            for (int j = 0; j < f.capacity; j++){
                prod[i+j] += degarr[i]*f.degarr[j];
            }
            
        }
        delete degarr;
        degarr = prod;
    
        return *this;
    }
    
    polyno operator = (polyno e){//overlaoded '=' operator
        this -> degarr = new int[e.capacity];
        for (int i = 0; i < e.capacity; i++){
            this -> degarr[i] = e.degarr[i];
        }
        this -> capacity = e.capacity;

        return *this;
    }
};

int main(){

    polyno a;
    a.setcoeff(0,-3); //syntax: class.setcoeff(degree,coefficient)
    a.setcoeff(1,4);
    a.setcoeff(2,3);
    a.setcoeff(3,-3);
    a.setcoeff(4,3);
    a.setcoeff(6,3);

    //a.printer();   

    polyno b;
    b.setcoeff(0,8);
    b.setcoeff(1,8);
    b.setcoeff(2,8);
    b.setcoeff(3,8);
    b.setcoeff(4,8);
    b.setcoeff(5,8);
    b.setcoeff(20,7);

    polyno c = a*b;

    c.printer();
    return 0;
}