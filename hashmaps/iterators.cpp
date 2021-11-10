#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    unordered_map<string,int> tempmap;
    tempmap["abc"] = 1;
    tempmap["abc2"] = 2;
    tempmap["abc3"] = 3;
    tempmap["abc4"] = 4;
    tempmap["abc5"] = 6;
    tempmap["abc6"] = 7;

    unordered_map<string,int>::iterator it = tempmap.begin();
    
    while (it != tempmap.end()){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
        it++;
    }
    //as this is an unordered map the values get printed at random.

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it1 = v.begin();
    
    while(it1 != v.end()){
        cout<<*it1<<endl;
        it1++;
    }
    //values get printed in the correct order

    unordered_map<string,int>::iterator it3 = tempmap.find("abc");//finds abc
    cout<<it3->second<<endl;
    tempmap.erase(it3);//erases it3's value

    unordered_map<string,int>::iterator it4 = tempmap.find("abc3");
    tempmap.erase(it3,it4);//erases it3's value and next 2 elements which is useless in the case of unordered map

    return 0;
}