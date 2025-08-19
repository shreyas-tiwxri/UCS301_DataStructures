#include<iostream>
using namespace std;
void BubbleSort(int arr[], int size){
    for(int i = 0; i<size - 1; ++i){
        for(int j = 0; j<size -1; ++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void PrintArray(int arr[], int size){
    for(int i = 0; i<size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array: ";
    PrintArray(arr, size);
    BubbleSort(arr, size);
    cout<<"Sorted Array: ";
    PrintArray(arr, size);

    return 0;

}