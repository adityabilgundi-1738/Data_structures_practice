#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=B9neYSq8qnQ&list=PLjeQ9Mb66hM3-awRd9EmL4dEhNc93MG-V&index=8
// https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1/?category

class Solution{
  public:
    int minOperation(int n){
        // top to bottom approach is a good approach here
        int steps = 0;
        while(n != 0){
            if(n % 2 == 0)n /= 2;
            else{
                n  = (n-1)/2;
            }
            steps++;
        }
        return steps;
    }
};

int main(){

    return 0;
}