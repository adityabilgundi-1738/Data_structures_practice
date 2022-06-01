#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
// moore's algorithm

int majorityElement(int a[], int size){
    int element, count;
    for(int i = 0; i < size; i++){
        if(i == 0){
            element = a[0];
            count = 1;
            continue;
        }
        if(a[i] != element){
            count--;
            if(count == 0){
                element = a[i];
                count = 1;
            }
            else{
                continue;
            }
        }
        else{
            count++;
        }
    }
    count = 0;
    for(int i = 0; i < size; i++){
        if(a[i] == element){
            count++;
        }
    }
    
    if(count > size/2){
        return element;
    }
    else{
        return -1;
    }
        
}

int main(){

    return 0;
}