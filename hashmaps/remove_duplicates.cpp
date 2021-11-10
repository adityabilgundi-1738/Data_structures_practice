#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> removeduplicates(int* a,int size){
    vector<int> output;
    unordered_map<int,bool> seen;

    for (int i = 0; i < size; i++){
        if(seen.count(a[i]) == true){
            continue;
        }
        else{
            seen[a[i]] = true;
            output.push_back(a[i]);
        } 
    }
    return output;
}

int main(){
    int a[] = {1,2,3,4,5,6,6,7,8,8,9,3,5,7,2,2};
    vector<int> ans = removeduplicates(a,16);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans.at(i)<<endl;
    }
    
    return 0;
}