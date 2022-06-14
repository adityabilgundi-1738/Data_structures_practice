#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

struct Item{
    int value;
    int weight;
};

bool comp(Item i1,Item i2){
    double unit1= (i1.value*1.0)/(i1.weight);
    double unit2= (i2.value*1.0)/(i2.weight);
    return (unit1>unit2);
}

class Solution{
    public:
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr,arr+n,comp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight>=W){
                double unit= (arr[i].value*1.0)/(arr[i].weight);
                ans+=(W*unit);
                break;
            }
            ans+=arr[i].value;
            W-=arr[i].weight;
        }
        return ans;
    }      
};

int main(){

    return 0;
}