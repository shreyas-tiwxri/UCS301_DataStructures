#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    node(int val): data(val),next(nullptr){}
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr){}

    void insert(int val){
        Node* newNode = new Node(val);
        if(!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    
    int deleteKey(int key){
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }


        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }
void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList list;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : arr)
        list.insert(val);

    int key = 1;
    int count = list.deleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    list.print();
    return 0;
}