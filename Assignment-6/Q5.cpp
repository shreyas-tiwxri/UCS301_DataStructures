#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    if (head == nullptr)
        return true; 

    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < 10) {  
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "...\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printList(head);
    cout << (isCircular(head) ? "Linked List is Circular\n" : "Linked List is NOT Circular\n");

    head->next->next->next->next = head;

    cout << (isCircular(head) ? "Linked List is Circular\n" : "Linked List is NOT Circular\n");

    return 0;
}
