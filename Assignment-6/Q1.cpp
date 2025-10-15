#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBegin(val);
            return;
        }
        Node* prev = head, *curr = head->next;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                prev->next = newNode;
                newNode->next = curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* curr = head, *prev = nullptr;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                        return;
                    }
                    Node* temp = head;
                    while (temp->next != head) temp = temp->next;
                    temp->next = head->next;
                    Node* del = head;
                    head = head->next;
                    delete del;
                    return;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    bool search(int key) {
        if (!head) return false;
        Node* curr = head;
        do {
            if (curr->data == key) return true;
            curr = curr->next;
        } while (curr != head);
        return false;
    }

    void display() {
        if (!head) {
            cout << "List Empty\n";
            return;
        }
        Node* curr = head;
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != head);
        cout << "(head)\n";
    }
};

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBegin(int val) {
        DNode* newNode = new DNode(val);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* curr = head;
        while (curr) {
            if (curr->data == key) {
                DNode* newNode = new DNode(val);
                newNode->next = curr->next;
                newNode->prev = curr;
                if (curr->next) curr->next->prev = newNode;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBegin(val);
            return;
        }
        DNode* curr = head->next;
        while (curr) {
            if (curr->data == key) {
                DNode* newNode = new DNode(val);
                newNode->prev = curr->prev;
                newNode->next = curr;
                curr->prev->next = newNode;
                curr->prev = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    void deleteNode(int key) {
        DNode* curr = head;
        while (curr) {
            if (curr->data == key) {
                if (!curr->prev) {
                    head = curr->next;
                    if (head) head->prev = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    if (curr->next) curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    bool search(int key) {
        DNode* curr = head;
        while (curr) {
            if (curr->data == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "List Empty\n";
            return;
        }
        DNode* curr = head;
        while (curr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    CircularLinkedList clist;
    DoublyLinkedList dlist;
    int choice, val, key, listType;
    while (1) {
        cout << "\nChoose List Type:\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\n";
        cin >> listType;
        if (listType == 3) break;
        while (1) {
            cout << "\nMenu:\n 1.Insert at Beginning\n2.Insert at End\n3.Insert After\n4.Insert Before\n5.Delete Node\n6.Search\n7.Display\n8.Change List/Exit\n";
            cin >> choice;
            if (choice == 8) break;
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    if (listType == 1) clist.insertAtBegin(val);
                    else dlist.insertAtBegin(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    if (listType == 1) clist.insertAtEnd(val);
                    else dlist.insertAtEnd(val);
                    break;
                case 3:
                    cout << "Enter value to insert after: ";
                    cin >> key;
                    cout << "Enter value to insert: ";
                    cin >> val;
                    if (listType == 1) clist.insertAfter(key, val);
                    else dlist.insertAfter(key, val);
                    break;
                case 4:
                    cout << "Enter value to insert before: ";
                    cin >> key;
                    cout << "Enter value to insert: ";
                    cin >> val;
                    if (listType == 1) clist.insertBefore(key, val);
                    else dlist.insertBefore(key, val);
                    break;
                case 5:
                    cout << "Enter value to delete: ";
                    cin >> key;
                    if (listType == 1) clist.deleteNode(key);
                    else dlist.deleteNode(key);
                    break;
                case 6:
                    cout << "Enter value to search: ";
                    cin >> key;
                    if (listType == 1)
                        cout << (clist.search(key) ? "Found\n" : "Not Found\n");
                    else
                        cout << (dlist.search(key) ? "Found\n" : "Not Found\n");
                    break;
                case 7:
                    if (listType == 1) clist.display();
                    else dlist.display();
                    break;
                default:
                    cout << "Invalid\n";
            }
        }
    }
    return 0;
}
