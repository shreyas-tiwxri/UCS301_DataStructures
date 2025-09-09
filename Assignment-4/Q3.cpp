#include<iostream>
using namespace std;
int main(){
    int arr[50], n;

    cout<<"Enter number of elements(even): "<<endl;
    cin>>n;
    if(n%2 != 0){
        cout << "Number of elements must be even!" << endl;
        return 0;
    }
    cout<<"Enter: "<<n <<"Elements: ";
    for(int i = 0;i < n;i++){
        cin>> arr[i];
    }
    int half = n/2;
    int result[50];
    int index = 0;
    for(int i = 0; i<half; i++){
        result[index++] = arr[i];
        result[index++] = arr[i+half];
    }
    cout<<"Interleaved output: "<<endl;
    for(int i = 0 ; i<n; i++){
        cout<<result[i]<<" ";
    } 
    cout<<endl;
}