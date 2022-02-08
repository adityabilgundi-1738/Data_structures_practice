#include<iostream>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int arr[26];
        for (int i = 0; i < 26; i++){
            arr[i] = 0;
        }
        int i = 0;
        while(s[i]){
            arr[s[i] - 97]++;
            i++;
        }
        int max = s[0];
        for (int i = 0; i < 26; i++){
            max = (s[i] > max) ? s[i] : max;
        }
        return max;
    }
};