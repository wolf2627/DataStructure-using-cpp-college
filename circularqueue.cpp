#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the circular queue

class CircularQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (front == (rear + 1) % MAX_SIZE);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Circular Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int data = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    CircularQueue cq;

    cout << "Circular Queue Operations:" << endl;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cq.display();

    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cq.enqueue(60); // This will result in a full queue
    cq.display();

    return 0;
}
