#include<iostream>
using namespace std;

class Dnode{
    public:
    int data;
    Dnode *prev, *next;
    Dnode(int val): data(val),prev(nullptr), next(nullptr){}
};
int sizeofDoublyLinkedList(DNode* head){
    int count = 0;
    Dnode* curr = head;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
};

class Node{
    public:
    int data;
    Node* next;
    Node(int val): data(val); next(nullptr){}
};

int sizeofCircularLinkedList(Node* head){
    if(!head) return 0;
    int count = 1;
    Node* curr = head->next;
    while(curr && curr != head){
        count++;
        curr = curr->next;
    }
    return count;
}

int main(){
    DNode* headD = new Dnode(10);
    headD->next = new Dnode(20);
    headD->next->prev = headD;
    headD->next->next = new DNode(30);
    headD->next->->next->prev = headD->nextD;

    cout<<"Size of Doubly Linked List."<<sizeofDoublyLinkedList(headD)<<endl;
    return 0;
}