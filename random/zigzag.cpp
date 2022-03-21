#include<iostream>

using namespace std;

string convert(string s, int numRows) {
    string res;
    for(int i = 0; i < numRows; ){
        res.push_back(s.at(i));
        if(numRows == 1){
            return s;
        }
        else if(numRows == 0){
            return s;
        }
        else{
            i += 2*numRows-3;  
        }
    }
    return res;
}

int main(){
    string a = "ADITYASBILGUNDI";
    a = convert(a,3);
    
    for (int i = 0; i < a.size(); i++){
        cout<<a.at(i)<<endl;
    }

    return 0;
}