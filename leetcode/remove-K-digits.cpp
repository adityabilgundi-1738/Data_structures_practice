#include<iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

class Solution {
private:
    void removeMax(string &num,int max){
        num.erase(num.begin() + max);
    }

    int findIndex(string num){
        int max = num[0];
        for(int j = 1; j <= num.size(); j++){
            if(num[j] > max){
                max = num[j];
            }
        }
        return max;
    } 
public:
    string removeKdigits(string num, int k) {
        for(int i = 0; i < k; i++){
            int max = findIndex(num);
            removeMax(num,max);
        }
        return num;
    }
};