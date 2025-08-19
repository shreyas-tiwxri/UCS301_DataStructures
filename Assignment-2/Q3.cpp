#include<iostream>
using namespace std;
int Findmissingnumber(int arr[], int size){
    int left = 0; 
    int right = size - 1;
    int start = arr[0];
    while(left<=right){
        int mid = left + (right - left)/2;
        int expected = start + mid;
        if(arr[mid] == expected){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
return start + left;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int missing = Findmissingnumber(arr, size);
    cout<<"Missing Number is: "<<missing<<endl;
    return 0;
}