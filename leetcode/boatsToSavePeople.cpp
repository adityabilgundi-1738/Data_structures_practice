#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        
        while(i <= j){
            if(people[j] == limit){
                boats++;
                j--;
            }
            else if(people[i] + people[j] > limit){
                boats++;
                j--;
            }
            else {
                boats++;
                i++;
                j--;
            }
        }
        return boats;
    }
};