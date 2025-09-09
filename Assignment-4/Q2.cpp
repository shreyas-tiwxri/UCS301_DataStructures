#include<iostream>
using namespace std;

class Queue {
    int front, rear, size, capacity;
    int* queue;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = 0;
        rear = capacity - 1;
        size = 0;
        queue = new int[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to dequeue\n";
            return;
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        cout << "Dequeued: " << item << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek.\n";
            return;
        }
        cout << "Front element is: " << queue[front] << endl;
    }
};

void menu() {
    int capacity;
    cout << "Enter the number of elements: ";
    cin >> capacity;

    Queue q(capacity);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if the queue is empty\n";
        cout << "4. Check if the queue is full\n";
        cout << "5. Peek front element\n";
        cout << "6. Exit\n";
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
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                q.peek();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}