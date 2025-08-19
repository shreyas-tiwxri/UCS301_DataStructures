#include<iostream>
using namespace std;
int BinarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]<target){
            left = mid + 1;
        }
        else{
            left = mid - 1;
        }
        }
        return -1;
    }
int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int result = BinarySearch(arr, size, target);
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found."<<endl;
    }
    return 0;
}