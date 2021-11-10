#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int max_freq(int* a,int size){
    unordered_map<int,int> seen;

    for (int i = 0; i < size; i++){
        seen[a[i]]++;
    }
    int index = 0,value = seen[0];

    for (int i = 1;i < seen.size(); i++){
        if(seen[i] > value){
            value = seen[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int a[] = {1,2,3,4,5,6,6,7,8,8,9,3,5,7,2,8,8,8,8,8,2};

    int ans = max_freq(a,16);
    cout<<ans<<endl;


    return 0;
}