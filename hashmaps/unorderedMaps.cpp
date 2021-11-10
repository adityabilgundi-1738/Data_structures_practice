#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<string,int> map;

    //insert elements
    //method 1
    pair<string,int> p("abc",1);
    map.insert(p);
    //method 2
    map["def"] = 2;

    //accessing elements
    //method 1
    cout<<map["abc"]<<endl;
    cout<<map["def"]<<endl;

    //method 2
    cout<<map.at("abc")<<endl;
    cout<<map.at("def")<<endl;

    //exceptions
    //cout<<map.at("ghi")<<endl;//gives error
    
    cout<<map["ghi"]<<endl;
    //this method creates a new index called "ghi" and assigns it the default value 0.

    //size function
    cout<<map.size()<<endl;

    //count() this counts the no of times the index "abc" has occoured soo it can either be 1 or 0.
    cout<<map.count("abc")<<endl;

    //erase()
    cout<<map.erase("ghi")<<endl;

    return 0;
}