#include<iostream>

using namespace std;

int sum_arr(int array[],int len){
    if(len == 0){
        return array[0];
    }
    
    return array[0] + sum_arr(array+1,--len);
}

int main(){
    int arr[] = {1,2,55,7,8,9,2,0,12};
    int len = 9;

    int sum = sum_arr(arr,len);
    cout<<"Sum = "<<sum<<endl;
    return 0;
}