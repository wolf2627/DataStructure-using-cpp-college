#include<iostream>

using namespace std;

#define size 10

class stack {
    int a[size];
    int top;

public:
    stack() {
        top = -1;
    }

    void push(int data) {
        if (top == size - 1) {
            cout << "Our stack is full buddy\n";
        } else {
            top++;
            a[top] = data;
        }
    }

    int pop() {
        int x = -1;
        if (top < 0) {
            cout << "Stack has no elements to remove\n";
        } else {
            x = a[top];
            top--;
        }
        return x;
    }

    void display() {
        if (top < 0) {
            cout << "Stack has no elements to print\n";
        } else {
            for (int i = top; i >= 0; i--) { 
                cout << a[i] << endl; 
            }
        }
    }
};

int main() {
    int ch, x;
    char c;
    stack s;
    do {
        cout << "1. Display\n";
        cout << "2. Push element\n";
        cout << "3. Pop element\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                s.display();
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> x;
                s.push(x);
                break;
            case 3:
                x = s.pop();
                if (x != -1)
                    cout << x << " is removed\n";
                break;
            case 4:
                return 0;
            default:
                cout << "Enter a valid choice\n";
                break;
        }
        cout << "Enter a character to continue....";
        cin >> c;
    } while (true);
    return 0;
}
