#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList list{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nulptr;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
            temp->next = newNode;
        }
    
    int findMiddle(){
        if(!head) return -1;

        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void Diplsay(){
        Node* temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->next) cout<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Linked List: ";
    list.display();

    cout << "Middle Element: " << list.findMiddle() << endl;

    return 0;
}
