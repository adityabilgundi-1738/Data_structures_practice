#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> intersection(int* a,int asize, int* b,int bsize){
    unordered_map<int,bool> map1,map2;
    vector<int> first,sec,intersection;

    for(int i = 0; i < asize; i++){
        if(map1.count(a[i]) == true){
            continue;
        }
        else{
            map1[a[i]] = true;
            first.push_back(a[i]);
        }
    }
    
    for(int i = 0; i < bsize; i++){
        if(map2.count(b[i]) == true){
            continue;
        }
        else{
            map2[b[i]] = true;
            sec.push_back(b[i]);
        }
    }

    for (int i = 0; i < map1.size(); i++){
        return;
    }
    

}

int main(){
    int a[] = {1,2,3,4,5,6,9,11,17};
    int b[] = {3,5,7,8,1,9,19};

    vector<int> c = intersection(a,9,b,7);

    return 0;
}