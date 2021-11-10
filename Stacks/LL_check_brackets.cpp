#include<iostream>
#include"stackUsingLL.h"
#include<string.h>

using std::cout;
using std::endl;

bool check_paran(string str){
    stack <char> stack; 
    char x;
    bool ans;

    for (int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == ')' || str[i] == ']' || str[i] == '}'){
            switch (str[i])
            {
            case '(':{
                stack.push(str[i]);
                break;
            }
            
            case ')':{
                x = stack.first();
                stack.pop();
                if(x == '[' || x == '{'){ 
                    return false;
                }
                else
                ans = true;
                break;
            }
            
            case '[':{
                stack.push(str[i]);
                break;
            }
            
            case ']':{
                x = stack.first();
                stack.pop();
                if(x == '(' || x == '{'){
                    return false;
                }
                ans = true;
                break;
            }
            
            case '{':{
                stack.push(str[i]);
                break;
            }
            
            case '}':{
                x = stack.first();
                stack.pop();
                if(x == '(' || x == '['){
                    return false;
                }
                ans = true;
                break;
            }
            }
        }
        else {
            continue;
        }
    }
    return ans;
    
}

int main(){
    string a;

    cout<<"Enter the string"<<endl;
    getline(cin,a);

    bool ans = check_paran(a);
    cout<<ans<<endl;

    return 0;
}