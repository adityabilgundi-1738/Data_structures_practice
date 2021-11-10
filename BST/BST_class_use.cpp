#include<iostream>
#include"bst_Class.h"

using namespace std;

int main(){
    bst b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    //b.deleteData(10);
    b.deletenode(100);//doesnt delete

    b.printer();

    return 0;
}