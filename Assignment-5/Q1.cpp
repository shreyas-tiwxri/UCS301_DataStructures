#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList{
    private:
    Node* head;
    
    public:
    LinkedList(){
        head = NULL;
    }

void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }


    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }


    void insertRelative(int val, int target, bool before) {
        Node* newNode = new Node(val);
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (before && head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Target node not found.\n";
            delete newNode;
            return;
        }
        if (before) {
            prev->next = newNode;
            newNode->next = curr;
        } else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }


    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deletefromend(){
        if(!head){
            cout<<"The list is empty."<<endl;
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next){
        temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Node not found.\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Node found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found.\n";
    }

    void displayList(){
        if(!head){
            cout<<"The list is empty.\n";
            return;
        }
        Node* temp = head;
        cout<<"Linked list: ";
        while(temp){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<"NULL \n";
    }
};

int main(){
    LinkedList list;
    int choice, val, target;
    bool before;
    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert before (1) or after (0)? ";
                cin >> before;
                list.insertRelative(val, target, before);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deletefromend();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteSpecific(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                list.searchNode(val);
                break;
            case 8:
                list.displayList();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }while(choice != 9);
    return 0;
}


