#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        int no_z = k/26;
        int remaining = n - no_z;
        
        string temp;
        if(no_z + remaining == n){
            for(int i = 0; i < remaining; i++){
                temp.push_back('a');
            }
            for(int i = 0; i < no_z; i++){
                temp.push_back('z');
            }
        }
        else if(no_z + remaining > n){
            for(int i = 0; i < remaining; i++){
                temp.push_back('a');
            }
            for(int i = 0; i < no_z; i++){
                temp.push_back('z');
            }
            int rem = no_z + remaining - n;
            temp.at(n-no_z) = 'z' - rem;
        }
        else if(no_z + remaining < n){
            for(int i = 0; i < remaining; i++){
                temp.push_back('a');
            }
            for(int i = 0; i < no_z; i++){
                temp.push_back('z');
            }
            int rem = n - no_z - remaining;
            temp.at(n-no_z-1) = 'a' + rem;
        }
        return temp;
    }
};

int main(){


    return 0;
}