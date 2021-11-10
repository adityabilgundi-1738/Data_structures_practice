#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;//static allocation

    vector<int>* a = new vector<int>();//dynamic allocation

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    //10,20,30

    v[1] = 69;

    //10,69,30
    v[3] = 42;
    v[4] = 1738;
    v[5] = 98;

    v.push_back(32);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;
    cout<<v[6]<<endl;
    
    v.at(1);
    v.at(2);
    v.at(3);
    v.at(4);
    
    return 0;
}