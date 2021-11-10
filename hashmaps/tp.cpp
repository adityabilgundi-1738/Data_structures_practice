#include<iostream>

using namespace std;

template<typename K,typename V>
class Hashnode{
    private:
    K key;
    V value;
    Hashnode* next;

    public:
    Hashnode(const K &key,const V &value) : key(key),value(value),next(NULL){}

    K getkey(){
        return key;
    }

    V getValue(){
        return value;
    }

    void setValue(V value){
        this->value = value;
    }

    void setKey(K key){
        this->key = key;
    }
};

int main(){


    return 0;
}