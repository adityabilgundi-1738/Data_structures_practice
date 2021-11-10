#include<iostream>

using namespace std;
#include"LL_queue.h"

int main(){
    queue <char> a;//queue <datatype> name(size);
    a.enqueue('a');
    a.enqueue('b');
    a.enqueue('c');
    a.enqueue('d');
    a.enqueue('e');
    a.enqueue('f');
    a.enqueue('g');
    a.enqueue('h');
    a.enqueue('i');

    cout<<a.front()<<endl;
    cout<<a.dequeue()<<endl;
    cout<<a.front()<<endl;
    cout<<a.dequeue()<<endl;
    cout<<a.front()<<endl;
    cout<<a.dequeue()<<endl;
    cout<<a.front()<<endl;
    cout<<a.dequeue()<<endl;

    cout<<a.getsize()<<endl;
    cout<<a.isempty()<<endl;

    return 0;
}