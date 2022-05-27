#include<bits/stdc++.h>
using namespace std;

void solve(string pass,int len){
    bool Cap = false, smol = false, digit = false, special = false;

    for(int i = 0; i < len; i++){
        if(65 <= (int)pass[i] <= 90){
            Cap = true;
        }
        else if(97 <= (int)pass[i] <= 122){
            smol = true;
        }
        else if(48 <= (int)pass[i] <= 57){
            digit = true;
        }
        else{
            special = true;
        }
    }

    if(!Cap) pass.push_back('A');
    if(!smol) pass.push_back('a');
    if(!digit) pass.push_back('1');
    if(!special) pass.push_back('%');

    cout<<pass<<endl;
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int len;
        cin>>len;
        char pass[len];
        cin.getline(pass,len);
        cout<<"Case #"<<i<<": ";
        solve(pass,len);
    }
    return 0;
}