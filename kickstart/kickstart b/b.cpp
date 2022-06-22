#include<bits/stdc++.h>
using namespace std;

vector<string> getFactors(long long num){
    vector<string> vct;
    for(long long i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            if(num/i == i){
                vct.push_back(to_string(i));
            }
            else{
                vct.push_back(to_string(i));
                vct.push_back(to_string(num/i));
            }
        }
    }
    return vct;
}

void helper(){
    long long num;
    cin>>num;

    long long count = 0;

    vector<string> vct = getFactors(num);
    for(auto it: vct){
        string temp = it;
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