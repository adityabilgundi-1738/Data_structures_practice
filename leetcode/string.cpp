#include<iostream>

using namespace std;

string defangIPaddr(string address){
    string temp;
    for(auto it: address){
        if(it == '.'){
           temp.push_back('[');
           temp.push_back('.');
           temp.push_back(']');
        }
        else{
            temp.push_back(it);
        }
    }
    return address;
}

int main(){
    return 0;
}