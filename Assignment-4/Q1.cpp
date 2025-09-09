#include<iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int* queue;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = 0;
        rear = -1;
        queue = new int[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        rear++;
        queue[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to dequeue\n";
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek.\n";
            return;
        }
        cout << "Front element is: " << queue[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

void menu() {
    int capacity;
    cout << "Enter the number of elements: ";
    cin >> capacity;

    Queue q(capacity);
    int choice;

    do {
        cout << "\n Menu: \n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if the queue is empty\n";
        cout << "4. Check if the queue is full\n";
        cout << "5. Peek front element\n";
        cout << "6. Display queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int item;
                cout << "Enter element to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            }
            case 2:
                q.dequeue();
                break;
            case 3:
                if(q.isEmpty()){
                    cout<<"Queue is empty."<<endl;
                }
                else{
                    cout<<"Queue is not empty."<<endl;
                }
                break;
            case 4:
                if(q.isFull()){
                    cout<<"Queue is full.";
                }
                else{
                    cout<<"Queue is not full.";
                }
                break;
            case 5:
                q.peek();
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
