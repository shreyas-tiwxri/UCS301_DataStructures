#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val): data(val),next(nullptr){}
};
void displayWithRepeatedHead(node* head){
    if(!head){
        cout<<"The list is empty."<<endl;
        return;
    }
    Node* curr = head;
    do{
        cout<<curr->data<<"";
        curr = curr->next;
    }while(curr != head);

    cout<<head->data<<endl;
}