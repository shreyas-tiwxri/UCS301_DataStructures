#include<iostream>
using namespace std;
class DNode{
    public:
    char data;
    Dnode* prev;
    Dnode* next;
    DNode(char val): data(val),prev(nullptr),next(nullptr){}
};

class DoublyLinkedList{
    public:
    DNode* head;
    DoublyLinkedList(): head(nullptr){}
    void insertAtEnd(char val){
        DNode* newNode = new DNode(val);
        if(!head){
            head = newNode;
            return;
        }
        DNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

bool isPlaindrome(){
    if(!head || !head->next){
        return true;
    }

    DNode* left = head;
    DNode* right = head;
    while(right->next)
    right = right->next;

    while(left != right && right->next != left){
        if(left->data != right->data)
        return false;
    left = left->next;
    right = right->prev;
    }
    return true;
}
};

int main() {
    DoublyLinkedList dll;

    string input;
    cout << "Enter characters for doubly linked list: ";
    cin >> input;

    for (char ch : input) {
        dll.insertAtEnd(ch);
    }

    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is not a palindrome.\n";

    return 0;
}