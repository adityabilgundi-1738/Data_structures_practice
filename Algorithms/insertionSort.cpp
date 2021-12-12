//this algorithm is efficient for small number of elements.
#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    int key, i ,j;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    cout<<"size = ?"<<endl;
    int size;
    cin>>size;
    int arr[size];
    
    for (int i = 0; i < size; i++){
        cout<<"Enter the array element "<<i<<endl;
        int num;
        cin>>num;
        arr[i] = num;
    }
    //array
    for (int i = 0; i < size; i++){
        cout<<arr[i];
    }

    insertionSort(arr, size);

    //sorted
    cout<<endl;

    for (int i = 0; i < size; i++){
        cout<<arr[i];
    }
}