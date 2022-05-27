#include<bits/stdc++.h>
using namespace std;

vector<int> getFactors(int num){
    vector<int> vct;
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            vct.push_back(i);
        }
    }
    return vct;
}

void helper(){
    int num;
    cin>>num;

    int count = 0;

    vector<int> vct = getFactors(num);
    for(auto it: vct){
        string temp = to_string(it);
        string rev = temp;
        reverse(rev.begin(), rev.end());

        if(temp.compare(rev) == 0) count++;
    }
    cout<<count<<endl;
}

int main(){
    int tt;
    cin>>tt;
    for(int i = 1; i <= tt; i++){
        cout<<"Case #"<<i<<": ";
        helper();
    }
    return 0;
}