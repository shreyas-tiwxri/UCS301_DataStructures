#include<iostream>
using namespace std;
int main(){
    int stack [100], top = -1, choice, value;
    do{
        cout<<"\n1. Push \n2. Display \n3. Pop \n4. Peek \n5. Is Full \n6. Exit";
        cin>>choice;
        switch(choice){
            case 1:
            if(top>=99){
                cout<<"Stack Overflow! "<<endl;
            }
            else{
                cout<<"Enter value: "<<endl;
                cin>>value;
                stack[++top] = value;
                cout<<value<<"Pushed.\n";
            }
            break;
            case 2:
            if(top == -1){
                cout<<"The stack is empty. \n";
            }
            else{
                cout<<"Stack elements (top to bottom):";
                for(int i = top; i >= 0; i--){
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
            }
            break;
            case 3:
            if(top == -1){
                cout<<"Stack Underflow! No elements to pop. \n";
            }
            else{
                cout<<stack[top--]<<"popped from stack."<<endl;
            }
            break;
            case 4:
            if(top == -1){
                cout<<"The stack is empty. Nothing to peek"<<endl;
            }
            else{
                cout<<"Top element is: "<<stack[top]<<endl;
            }
            break;
            case 5:
            if(top >= 99){
                cout<<"The stack is full. "<<endl;
            }
            else{
                cout<<"The stack isn't full. "<<endl;
            }
            break;
            case 6:
            cout<<"Exiting program. \n";
            break;
            default:
            cout<<"Invalid choice. Please try again. \n";
        }
    } while(choice != 6);
}
